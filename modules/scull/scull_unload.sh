#!/bin/bash

module="scull"
device="scull"
mode="664"

/sbin/rmmod ./$module.ko $* || exit 1

rm -f /dev/${device}[0-3]

echo "rmmod $module"
echo "rm node /dev/$device[0-3]"
