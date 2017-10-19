#pragma once
#ifndef PERSON_H
#define PERSON_H

	class Person {
		private:
			char name[20];
			int age;
		public:
			void setVals(char[], int);
			void print(void);
	};

#endif