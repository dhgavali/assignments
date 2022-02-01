// cricket

#include <stdio.h>
#include <string.h>
struct data
{
	char name[10], country[10], category[10];
	int age, odi, twenty, score, wicket;
};
char highscore[10], x[10];
void batsmancountry(struct data a[], int n)
{
	int i, x = 0;
	char b[10];
	printf("enter country name to find no of batsman in that country==\n");
	scanf("%s", b);
	for (i = 0; i < n; i++)
	{
		if (strcmp(a[i].country, b) == 0 &&
			strcmp(a[i].category, "batsman") == 0)
			x++;
	}
	printf("no of players are == %d\n", x);
}
void sort(struct data a[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		for (j = i - 1; j >= 0 && a[j].score < a[i].score; j--)
		{
			temp = a[j].score;
			a[j].score = a[i].score;
			a[i].score = temp;
		}
	}
	printf("name of players after sorting in ascending order== \n");
	for (i = 0; i < n; i++)
	{
		printf("%d)%s\n", i + 1, a[i].name);
	}
	strcpy(highscore, a[n - 1].name);
}
void highwicket(struct data a[], int n)
{
	int i, max = a[0].wicket;
	strcpy(x, a[0].name);
	for (i = 0; i < n; i++)
	{
		if (max < a[i].wicket)
		{
			max = a[i].wicket;
			strcpy(x, a[i].name);
		}
	}
	printf("the bowler who taken high no of wickets== %s\n", x);
}
void bowlercountry(struct data a[], int n)
{
	int i, x = 0;
	char b[10];
	printf("enter country name to find no of bowler in that country==\n");
	scanf("%s", b);
	for (i = 0; i < n; i++)
	{
		if (strcmp(a[i].country, b) == 0 &&
			strcmp(a[i].category, "bowler") == 0)
			x++;
	}
	printf("no of players are == %d\n", x);
}
void batsmanhighestscore(struct data a[], int n)
{
	printf("Batsman with highest average score is == %s\n", highscore);
}
void tabularform(struct data a[], int n)
{
	printf("Data in tabular form==\n");
	printf("Name\tAge\tCountry\tCategory\tNo.ofODI\tNo.of20-20\n");
	for (int i = 0; i < n; i++)
	{
		printf(
			"%s\t%d\t%s\t%s\t%d\t%d\n",
			a[i].name,
			a[i].age,
			a[i].country,
			a[i].category,
			a[i].odi,
			a[i].twenty);
	}
}

int main()
{
	int n, i;
	printf("Enter no of players= \n");
	scanf("%d", &n);
	struct data a[n];
	int temp;
	for (i = 0; i < n; i++)
	{
		printf("\nenter details of %dth player= \n", i + 1);
		printf("name= \n");
		scanf("%s", a[i].name);
		printf("age= \n");
		scanf("%d", &a[i].age);
		printf("country= \n");
		scanf("%s", a[i].country);
		printf("category=  \n");
		scanf("%s", a[i].category);
		printf("no of odi played==\n");
		scanf("%d", &a[i].odi);
		printf("no of 20-20 played= \n");
		scanf("%d", &a[i].twenty);
		printf("enter average score= \n");
		scanf("%d", &a[i].score);
		printf("no of wickets taken= \n");
		scanf("%d", &a[i].wicket);
	}
	i = 1;
	while (i != 0)
	{
		printf("\n\n");
		printf("enter choice as follows==\n");
		printf("1) Number of batsman of a particular country \n");
		printf("2) Sort the Batsman as per the average batting score\n");
		printf("3) Batsman with highest average score\n");
		printf("4) Number of bowlers of a particular country\n");
		printf("5) The bowler that has taken a maximum no of wickets\n");
		printf("6) Show players the entire Display board information\n");
		printf("7) for end\n");
		printf("\n");
		printf("enter your choice== \n");
		scanf("%d", &temp);
		switch (temp)
		{
		case 1:
		{
			batsmancountry(a, n);
			printf("\n          ******          \n");
			break;
		}
		case 2:
		{
			sort(a, n);
			printf("\n          ******          \n");
			break;
		}
		case 3:
		{
			batsmanhighestscore(a, n);
			printf("\n          ******          \n");
			break;
		}
		case 4:
		{
			bowlercountry(a, n);
			printf("\n          ******          \n");
			break;
		}
		case 5:
		{
			highwicket(a, n);
			printf("\n          ******          \n");
			break;
		}
		case 6:
		{
			tabularform(a, n);
			printf("\n          ******          \n");
			break;
		}
		case 7:
		{
			i = 0;
		}
		}
	}
	return 0;
}