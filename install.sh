#! /bin/bash

set -e
export CXX=g++-6

verbose=0
cflag=false
mflag=false
iflag=false
jflag=8
fflag=false
pflag=false
tflag=false

while getopts 'cmifptvj:' flag; do
  case "${flag}" in
    c) cflag=true ;;
    m) mflag=true ;;
	i) iflag=true ;;
    j) jflag="${OPTARG}" ;;
	f) fflag=true ;;
	p) pflag=true ;;
	t) tflag=true ;;
    # f) files="${OPTARG}" ;;
    v) verbose=1 ;;
    *) error "Unexpected option ${flag}" ;;
  esac
done

if $fflag ;
	then
		rm -rf build
        rm -rf /usr/local/include/gem
        # sh uninstall.sh || true
fi

[ -d build ] || mkdir build
cd build

if $cflag ;
	then
		cmake -DCMAKE_BUILD_TYPE=Release ..
fi
if $mflag;
	then
		make -j${jflag} VERBOSE=${verbose}
fi
if $iflag ;
	then
		make -j${jflag} install
		cp install_manifest.txt ..
fi
if $tflag ;
	then
		if ! $iflag ;
			then
				make -j${jflag} install
				cp install_manifest.txt ..
		fi
		env CTEST_OUTPUT_ON_FAILURE=${verbose} make -j${jflag} check
fi

cd ..

if $pflag ;
	then
		rm -r build
fi