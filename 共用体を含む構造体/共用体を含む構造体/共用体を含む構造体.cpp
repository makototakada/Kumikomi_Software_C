#include <stdio.h>

struct subject1 {

	int language;
	int english;
	int society;
};
struct subject2 {

	int math;
	int english;

};
struct record {

	int no;
	char name[40];
	int choice;
	union subject {

		struct subject1 s1;
		struct subject2 s2;

	}sub;

};

int main(void) {

	struct record cls[20] = {

	    {1001,   "小柳幸江", 1, 76, 87, 69},
	    {1002,     "大場優", 2, 79, 48,  0},
	    {1003, "新庄あやか", 2, 85, 98,  0},
	    {1004,   "野崎栄一", 1, 43, 76, 56},
	    {1005,   "本多健也", 1, 69, 91, 69},
	    {  -1,           "", 0,  0,  0,  0} 

	};
	int i = 0;

	while (cls[i].no != -1) {

		printf("%4d %-13s ", cls[i].no, cls[i].name);

		if (cls[i].choice == 1) {

			printf("国語：%3d 英語：%3d 社会：%3d\n",
				cls[i].sub.s1.language, cls[i].sub.s1.english, cls[i].sub.s1.society);

		}
		else {

			printf("数学：%3d 英語：%3d\n",
				cls[i].sub.s2.math, cls[i].sub.s2.english);
			//構造体の中に共用体を含む場合、全てのタグとメンバをつなげて記述する必要がある。

		}

		i++;

	}

	return 0;
}