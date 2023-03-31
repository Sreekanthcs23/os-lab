#! /bin/bash
echo `cat /etc/os-release`
echo ""
echo `cat /etc/shells`
echo ""
echo `xinput --list`
echo ""
echo `cat /proc/cpuinfo | head`
echo ""
echo `cat MemTotal /proc/meminfo | head`
echo ""
echo `lshw -c disk | head`
echo ""
echo `mount | column -t | head`
