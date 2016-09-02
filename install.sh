#! /bin/bash

set -e
export CXX=g++-6

verbose=0
cflag=false
mflag=false
iflag=false
fflag=false
pflag=false
tflag=false

while getopts 'cmifptv' flag; do
  case "${flag}" in
    c) cflag=true ;;
    m) mflag=true ;;
	i) iflag=true ;;
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
fi

[ -d build ] || mkdir build
cd build

if $cflag ;
	then
		cmake -DCMAKE_BUILD_TYPE=Release ..
fi
if $mflag;
	then
		make -j8 VERBOSE=${verbose}
fi
if $iflag ;
	then
		make -j8 install
		cp install_manifest.txt ..
fi
if $tflag ;
	then
		if [[ -n $iflag ]] ;
			then
				make -j8 install
				cp install_manifest.txt ..
		fi
		env CTEST_OUTPUT_ON_FAILURE=${verbose} make -j8 check
fi

cd ..

if $pflag ;
	then
		rm -r build
fi