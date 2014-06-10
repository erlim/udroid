#!/system/bin/sh

chmod 0777 /data/etc/udroid.ko
insmod /data/etc/udroid.ko
chmod 0777 /data/etc/udroidd
/data/etc/udroidd
