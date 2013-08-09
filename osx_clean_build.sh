start_dir=$PWD
source_dir=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
base_build_dir="${HOME}/Desktop/Hazmat_Build"

if [[ -z $1 ]] ; then
    echo "Usage: sh osx_clean_build.sh <build_type>*"
    echo "           where <build_type> is"
    echo "                Debug"
    echo "                Release"
    exit 1
fi

function cleanBuildWithXcode()
{
    build_type=$1
    build_dir=${base_build_dir}_${build_type}

    rm -rf ${HOME}/Library/Developer/Xcode/DerivedData/Hazmat*

    if [ ! -d $build_dir ] ; then
        mkdir $build_dir
    fi

    cd $build_dir && rm -rf *
    cmake -G "Xcode" $source_dir
    xcodebuild -target install -configuration $build_type
}

for cur_build_type in "$@";
do
    cleanBuildWithXcode $cur_build_type
done

cd $start_dir
