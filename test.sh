#!/bin/sh

tests_dir="./tests"

if [ -z "$1" ]
then
	tests=$(ls $tests_dir/ft_*_test.c | xargs basename -s _test.c)
	for test in ${tests//\\n/ }; do
		./$0 "$test"
	done
	exit 0
fi

tests_lib_dir="$tests_dir/lib"
tests_bin_dir="$tests_dir/bin"
exec_file="$tests_bin_dir/$1_test"
test_file="$tests_dir/$1_test.c"
tests_src_files="$tests_lib_dir/*.c"
lib_file="./libft.a"

mkdir -p "$tests_bin_dir"

cc -Wall -Wextra -Werror -o "$exec_file" \
	-I "$tests_lib_dir" -I ./ \
	$test_file $tests_lib_dir/*.c $lib_file \
	&& "$exec_file"
