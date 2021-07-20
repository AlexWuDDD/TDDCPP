#!/bin/sh

spec=1

# create distribution file
make dist

# create tar archive and signature
tarArchive=rlog-1.4.tgz
mv rlog-1.4.tar.gz $tarArchive
# let the user know why they're being asked for a passpharse
echo "Signing tar archive - enter GPG password";
gpg --detach-sign -a $tarArchive

# create rpms
cp $tarArchive /usr/src/packages/SOURCES
echo "Building signed RPM files - enter GPG password";
rpmbuild -ba --sign rlog.spec

# move all distribution files to dist directory
mkdir dist
mv $tarArchive dist
mv $tarArchive.asc dist
mv /usr/src/packages/SRPMS/rlog-1.4-$spec.src.rpm dist
mv /usr/src/packages/RPMS/i586/rlog-1.4-$spec.i586.rpm dist

# cleanup
rm /usr/src/packages/SOURCES/$tarArchive

