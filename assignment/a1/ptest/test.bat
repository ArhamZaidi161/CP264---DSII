
7z.exe e *.zip *.h *.c *.txt -r -y

echo batch public test > test_result.txt
gcc mychar.c mychar_ptest.c -o q1 2> q1c.txt
echo q1 >> test_result.txt
q1.exe >> test_result.txt

gcc powersum.c powersum_ptest.c -o q2 2> q2c.txt
echo q2 >> test_result.txt
q2.exe >> test_result.txt

gcc quadratic.c quadratic_ptest.c -o q3 2> q3c.txt
echo q3 >> test_result.txt
q3.exe >> test_result.txt


fc test_result.txt test_solution.txt > test_report.txt

