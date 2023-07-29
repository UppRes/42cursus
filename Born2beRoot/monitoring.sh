#!/bin/bash
wall    $'#Architecture: ' `hostnamectl | grep "Operating System" | cut -d ':' -f2- ` `grep "model name" /proc/cpuinfo | cut -d ':' -f2-` `arch` \
$'\n#CPU physical: '`grep "processor" /proc/cpuinfo | wc -l` \
$'\n#vCPU:  '`cat /proc/cpuinfo | grep processor | wc -l` \
$'\n'`free -m | awk 'NR==2{printf "#Memory Usage: %s/%sMB (%.2f%%)", $3,$2,$3*100/$2 }'` \
$'\n'`df -Bm | grep "^/dev" | grep -v "/boot$" | awk '{size += $2}{used += $3}{top += $5} END {printf("#Disk Usage: %dMb/%dGb (%d%%)",used,size/1024,top)}'` \
$'\n'`top -bn1 | grep "^%Cpu" | awk '{printf "#CPU Load: %.1f%%", $2 + $4}'` \
$'\n#Last boot: ' `who -b | awk '{print $3" "$4" "$5}'` \
$'\n#LVM use: ' `lsblk | grep lvm | awk '{if ($1) {print "yes";exit;} else {print "no"} }'` \
$'\n#Connection TCP:' `netstat -an | grep ESTABLISHED |  wc -l` \
$'\n#User log: ' `who | wc -l` \
$'\nNetwork: IP ' `hostname -I`"("`ip a | grep link/ether | awk '{print $2}'`")" \
$'\n#Sudo:  ' `journalctl _COMM=sudo | grep COMMAND | wc -l
