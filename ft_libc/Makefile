file := ft_isalpha

test:
	clang $(file).c -o out_test_$(file)
	./out_test_$(file)

run:
	clang -Wall -Werror -Wextra $(file).c -o out_test_$(file)
	./out_test_$(file)