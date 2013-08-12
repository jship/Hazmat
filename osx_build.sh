start_dir=$PWD
source_dir=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
base_build_dir="${HOME}/Desktop/Hazmat_Build"

if [[ -z $1 ]] ; then
    echo "Usage: sh osx_build.sh <build_type>*"
    echo "           where <build_type> is"
    echo "                Debug"
    echo "                Release"
    exit 1
fi

function buildWithXcode()
{
    build_type=$1
    build_dir=${base_build_dir}_${build_type}

    if [ ! -d $build_dir ] ; then
        echo "$build_dir does not exist!"
        echo "Run a clean build prior to running this script."
        exit 1
    fi

    cd $build_dir
    xcodebuild -target install -configuration $build_type
}

for cur_build_type in "$@";
do
    buildWithXcode $cur_build_type
done

cd $start_dir