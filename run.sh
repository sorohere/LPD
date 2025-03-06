textbook: https://www.doc-developpement-durable.org/file/Projets-informatiques/cours-&-manuels-informatiques/Linux/Linux%20Kernel%20Development,%203rd%20Edition.pdf

tar -xvf linux-6.13.5.tar.xz
cd linux-6.13.5/
bison --version // 3.7+


bison: make sure to do in linux-6.13.5/ directory
wget http://ftp.gnu.org/gnu/bison/bison-3.8.2.tar.gz
tar -xvzf bison-3.8.2.tar.gz
cd bison-3.8.2
./configure --prefix=$HOME/local
make -j$(nproc)
make install
export PATH=$HOME/local/bin:$PATH

bison --version // 3.7+
cd ..
bison --version // 3.7+



continue.. 
 make defconfig
