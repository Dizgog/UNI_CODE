#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



typedef struct Student {
	char name[30];
	char surname[30];
	int course;
	double average; 		// average grade

	int load; 				// number of courses
	char courses[10][30]; 	// course names
	int grades[10]; 		// course grades

	char languages[100];		// spoken languages

} Student;

void printStudent(Student s);

void generate(int size);


void printStudent(Student s){

	printf("%-10s %-10s %dc.,   avg. %4.1f, %d courses", s.name, s.surname, s.course, s.average, s.load);
	for (int i = 0; i < s.load; ++i){
		printf(", %s %d", s.courses[i], s.grades[i]);
	}
	printf(", languages: %s\n", s.languages);

}

char names[30][30] = {
	"Alex", "Robert", "Jessie", "Adam", "Sole",
	"Jamie", "Jenny", "Alice", "Victor", "Charlie",
	"Matt", "Jerry", "George", "Jim", "Luke",
	"Debora", "Kim", "Melissa", "Richard", "Julie",
	"Angelina", "Betty", "Helen", "Jane", "Sarah",
	"Kylie", "Arnold", "Karl", "Wilhelm", "Eve"
};
char surnames[30][30] = {
	"Smith", "Doe", "Perry", "Brightman", "Lockwood",
	"Enderman", "Brighthill", "Sleight", "Note", "Wood",
	"Sheen", "Hudson", "King", "de Vito", "Norman",
	"Leben", "Quarry", "Hat", "Damon", "Thornton",
	"Davison", "Madsen", "Stapleton", "Wozniak", "Darry",
	"Sadman", "Gibbs", "Gibson", "Druddle", "Kesting"
};
char courses[10][30] = {
	"Algebra", "Computer programming", "Operating systems", "Physics", "Philosophy",
	"Calculus", "Set theory", "Algorithms", "Discrete mathematics", "Computer networks"
};
char languages[5][20] = {
	"English", "Russian", "Spanish", "French", "Lithuanian"
};

void generate(int size){
	srand(time(NULL));
	FILE *db = fopen("db.bin", "wb");
	if (db != NULL){
		fwrite(&size, sizeof(int), 1, db);
		for(int j = 0; j < size; ++j){
			Student s = { "", "", 0, 0.0, 0, { 0 }, { 0 }, "" };
			strcpy(s.name, names[rand()%30]);
			strcpy(s.surname, surnames[rand()%30]);
			s.course = rand()%4+1;
			s.load = 0;

			for(int i = 0; i < 10; ++i){
				if (rand()%3 == 0){
					strcpy(s.courses[s.load], courses[rand()%10]);
					s.grades[s.load] = rand()%72;
					if (s.grades[s.load] < 12){
						s.grades[s.load] = 1 + s.grades[s.load]/3;
					} else {
						s.grades[s.load] = 5 + (s.grades[s.load]-12)/10;
					}
					s.average += s.grades[s.load];
					++(s.load);
				}
			}
			s.average /= s.load;

			if (rand()%size < size/10)
				s.average += (rand()%10 - 5)/3;
			if (s.load == 0){
				s.average = 0;
			}

			strcat(s.languages, languages[0]);
			for(int i = 1; i < 5; ++i){
				if (rand()%4 == 0){
					strcat(s.languages, " ");
					strcat(s.languages, languages[i]);
				}
				if ((i == 4) && (strlen(s.languages) == 0))
					i = 0;
			}

			printStudent(s);
			fwrite(&s, sizeof(s), 1, db);
		}
		fclose(db);
	}

}

int main(int argc, char *argv[]) {

	printf("This will generate db.bin in the current folder...\n");
	if (argc > 1){
		int size = atoi(argv[1]);
		if ((size >= 1000) || (size < 1)){
			printf("Error! Value %d out of range\n", size);
			return 0;
		}
		generate(size);
		printf("Success!\n");
	} else {
		printf("Error! Please specify db size.\n");
		printf("Usage: generator.exe size (replace size with actual value)\n");
	}
	return 0;
}
