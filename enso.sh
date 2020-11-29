#!/usr/bin/sh
#
# COPYRIGHT (c) 2016 Wolfgang Morawetz wolfgang.morawetz@gmail.com
#
# GNU GENERAL PUBLIC LICENSE
#    Version 3, 29 June 2007
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Name:   enso.sh
# Desc:   None configurable based arch linux installer (for my enso)
# Thanks to Nick ... https://nerdstuff.org/posts/2020/2020-004_arch_linux_luks_btrfs_systemd-boot/


# //// DEBUG ////
set -o errexit  # script exit when a command fails ( add "... || true" to allow fail)
# set -o nounset  # script exit when it use undeclared variables
set -o xtrace   # trace for debugging
# set -o pipefail # exit status of last command that throws a non-zero exit code

# //// CONFIGURE ////
declare -A D0 # Main device
declare -A D1 # Home device
D0+=( [n]="/dev/vda" [efi]="/dev/vda1" [swap]="/dev/vda2" [root]="/dev/vda3" )
# D1+=( [n]="/dev/vdb" [home]="/dev/vdb1" )

# //// Partitioning ////
sgdisk --zap-all "${D0[n]}"
# sgdisk --zap-all "${D1[n]}"

sgdisk -n 0:0:+550M -t 0:ef00 -c 0:EFI "${D0[n]}"
sgdisk -n 0:0:+8GiB -t 0:8200 -c 0:SWAP "${D0[n]}"
sgdisk -n 0:0:0 -t 0:8300 -c 0:ROOT "${D0[n]}"
# sgdisk -n 0:0:0 -t 0:8300 -c:HOME "${D1[n]}"

# //// Encryption ////
# Note:
# Encrypt only home?
# With?
# Decrypt on logon with DM?

# //// File system creation ////
mkfs.vfat -F32 -n "EFI" "${D0[efi]}" 
mkswap -L "SWAP" "${D0[swap]}"
mkfs.btrfs -f -L "ROOT" "${D0[root]}"
# mkfs.btrfs -f -L "HOME" "${D1[home]}"

# //// Create and mount subvolumes ////
mount "${D0[root]}" /mnt
btrfs sub create /mnt/@
btrfs sub create /mnt/@home
btrfs sub create /mnt/@pkg
btrfs sub create /mnt/@snapshots
btrfs sub create /mnt/@btrfs
umount /mnt

# //// Mount the subvolumes ////
mount -o noatime,nodiratime,compress=zstd,space_cache,ssd,subvol=@ "${D0[root]}" /mnt
mkdir -p /mnt/{boot,home,var/cache/pacman/pkg,.snapshots,btrfs}
mount -o noatime,nodiratime,compress=zstd,space_cache,ssd,subvol=@home "${D0[root]}" /mnt/home
#mount -o noatime,nodiratime,compress=zstd,space_cache,ssd,subvolid=5 "${D1[home]}" /mnt/home
mount -o noatime,nodiratime,compress=zstd,space_cache,ssd,subvol=@pkg "${D0[root]}" /mnt/var/cache/pacman/pkg
mount -o noatime,nodiratime,compress=zstd,space_cache,ssd,subvol=@snapshots "${D0[root]}" /mnt/.snapshots
mount -o noatime,nodiratime,compress=zstd,space_cache,ssd,subvolid=5 "${D0[root]}" /mnt/btrfs

# //// Mount EFI partition ////
mkdir /mnt/boot
mount "${D0[root]}" /mnt/boot

# //// Base system ////
# Install Arch Linux with (adjust this list to your needs)
pacstrap /mnt linux base base-devel btrfs-progs intel-ucode neovim

# //// Generate /etc/fstab ////
genfstab -U /mnt >> /mnt/etc/fstab

# //// System configuration ////
# Locale... I'm from vienna, austria :)
echo "envy" > /mnt//etc/hostname
echo LANG=de_AT.UTF-8 > /etc/locale.conf
myLocale="de_AT.UTF-8 UTF8"; sed -i "/^#$myLocale/ c$myLocale" /mnt/etc/locale.gen
myLocale="de_AT ISO-8859-1"; sed -i "/^#$myLocale/ c$myLocale" /mnt/etc/locale.gen
myLocale="de_AT@euro ISO-8859-15"; sed -i "/^#$myLocale/ c$myLocale" /mnt/etc/locale.gen
# Keyboard
echo KEYMAP=de-latin1 > /mnt/etc/vconsole.conf
echo FONT=lat9w-16 >> /mnt/etc/vconsole.conf
# Time zone
ln -sf /mnt/usr/share/zoneinfo/Europe/Vienna /mnt/etc/localtime
echo "Rest....?"
arch-chroot /mnt/



