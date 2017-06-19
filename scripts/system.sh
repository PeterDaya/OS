#!/bin/sh
echo "***** HOST INFORMATION *****"
hostnamectl
echo ""

echo "***** Working Directory INFORMATION *****"
ls -alf
echo ""

echo "***** Active Users *****"
who
echo ""

echo "***** Hard Disk DISK SPACE USAGE *****"
df -h
echo ""

echo " ***** Additional Memory Information *****"
free
echo ""

echo "***** Uptime Information *****"
uptime
echo ""

echo "***** Highly Active Processes *****"
ps -eo %mem,%cpu,comm --sort=-%mem | head -n 11
