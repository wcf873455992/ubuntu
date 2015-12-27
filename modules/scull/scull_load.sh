#!/bin/bash

module="scull"
device="scull"
mode="664"

/sbin/insmod ./$module.ko $* || exit 1

rm -f /dev/${device}[0-3]

major=$(awk "\$2=   =\"$module\" {print \$1}" /proc/devices)
#awk -F: '/scull/{print $1}'  /proc/devices
major="250"

mknod /dev/${device}0 c ${major} 0
mknod /dev/${device}1 c ${major} 1
mknod /dev/${device}2 c ${major} 2
mknod /dev/${device}3 c ${major} 3


group="staff"
grep -q '^staff:' /etc/group || group="wheel"

chgrp $group /dev/${device}[0-3]
chmod $mode /dev/${device}[0-3]