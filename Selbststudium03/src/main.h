static const int MAX_LENGTH = 100;
static const int HIGHEST_MARK = 6;
static const int LOWEST_MARK = 1;

void empty_stdin(void);
double get_average(int numbers[], int length);
int get_highest_number(int numbers[], int length);
int get_lowest_number(int numbers[], int length);
int amount_same_element_in_array(int marks[], int length, int element);
int amount_above_delimeter(int marks[], int length, int delimeter);
int *points_to_mark(int points[], int length, int max_points);
void calculate_statistic(int marks[], int length, int max_points);
