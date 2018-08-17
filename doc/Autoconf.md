#### Install GNU Autotools for Mac Users

Unfortunately the development tools provided by XCode no longer include the Autotools Suite from GNU. This file is intended to provided to instructions for users to install these tools, since documntation seems to be lacking.

First a build variable is created in the user's home directory. Please feel free to change the build directory's path to wherever you'd like it to go.

```
cd
export $build =~/opt #or whereever you'd like to build
mkdir -p $build
```

Then the source code is downloaded to the build directory.

```
cd $build
curl -OL http://ftpmirror.gnu.org/autoconf/autoconf-latest.tar.xz
```

There will be some output as the tarball is downloaded. This is normal.
Next the zipped tarball needs to be uncompressed, and pathed into.

```
tar xzf autoconf-latest.tar.xz
cd autoconf-*
```

Configure, make, and install.
```
./configure
make
sudo make install
```
Again, lots of output here. This is normal.

Test to make sure Autoconf was installed with
```
autoconf --version
```

Hope this helps.
