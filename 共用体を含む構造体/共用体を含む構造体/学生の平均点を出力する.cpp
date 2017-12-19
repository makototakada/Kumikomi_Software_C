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
	double ave;

};

int main(void) {

	struct record cls[20] = {

		{ 1001,   "¬–öK]", 1, 76, 87, 69, 0.0 },
		{ 1002,     "‘åê—D", 2, 79, 48,  0, 0.0 },
		{ 1003, "V¯‚ ‚â‚©", 2, 85, 98,  0, 0.0 },
		{ 1004,   "–ìè‰hˆê", 1, 43, 76, 56, 0.0 },
		{ 1005,   "–{‘½Œ’–ç", 1, 69, 91, 69, 0.0 },
		{   -1,           "", 0,  0,  0,  0, 0.0 }

	};
	int i = 0;

	while (cls[i].no != -1) {

		printf("%4d %-13s ", cls[i].no, cls[i].name);

		if (cls[i].choice == 1) {

			cls[i].ave = (double) (cls[i].sub.s1.language + cls[i].sub.s1.english + cls[i].sub.s1.society) / 3.00;

			printf("‘ŒêF%3d ‰pŒêF%3d Ğ‰ïF%3d •½‹ÏF%5.2f\n",
				cls[i].sub.s1.language, cls[i].sub.s1.english, cls[i].sub.s1.society, cls[i].ave);

		}
		else {

			cls[i].ave = (double) (cls[i].sub.s2.math + cls[i].sub.s2.english) / 2.00;

			printf("”ŠwF%3d ‰pŒêF%3d           •½‹ÏF%5.2f\n",
				cls[i].sub.s2.math, cls[i].sub.s2.english, cls[i].ave);

		}

		i++;

	}

	return 0;
}