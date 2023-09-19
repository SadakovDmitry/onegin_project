g++ -c -Wall -Wextra -fsanitize=address sort_from_start.cpp -o sort_from_start.o
g++ -c -Wall -Wextra -fsanitize=address Evgeniy_Onegin.cpp -o Evgeniy_Onegin.o
g++ -c -Wall -Wextra -fsanitize=address sort_end.cpp -o sort_end.o
g++ -c -Wall -Wextra -fsanitize=address Qsort_Onegin.cpp -o Qsort_Onegin.o
g++ -c -Wall -Wextra -fsanitize=address Input.cpp -o Input.o
g++ -c -Wall -Wextra -fsanitize=address Other_func.cpp -o Other_func.o
g++ -Wall -Wextra -fsanitize=address Evgeniy_Onegin.o sort_from_start.o sort_end.o Qsort_Onegin.o Input.o Other_func.o -o Onegin
./Onegin
