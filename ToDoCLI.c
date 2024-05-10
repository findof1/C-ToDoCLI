#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// compile cmd: gcc -g -o ToDoCLI.exe ./ToDoCLI.c
// run cmd: ./ToDoCLI.exe

int main()
{
  struct task
  {
    int id;
    char name[50];
    bool complete;
  };
  struct task tasks[100];
  for (int i = 0; i < 100; i++)
  {
    tasks[i].id = 0;
    strcpy(tasks[i].name, "");
    tasks[i].complete = false;
  }
  char cmd[50];
  int lastId = 0;
  while (true)
  {
    printf("\nType a command (type /help for help).\n");
    scanf(" %s", &cmd);

    if (strcmp(cmd, "/exit") == 0)
    {
      return 0;
    }

    if (strcmp(cmd, "/help") == 0)
    {
      printf("\nCommands are:\n");
      printf("/help -shows a list of commands\n");
      printf("/exit -exits the program\n");
      printf("/list -lists all to-do items\n");
      printf("/newTask -creates a new task\n");
      printf("/deleteTask -deletes a task by id\n");
      printf("/toggleCompletion -toggles the completion of a task by id\n\n");
    }

    if (strcmp(cmd, "/list") == 0)
    {
      for (int i = 0; i < 100; i++)
      {
        if (tasks[i].id != 0)
        {
          printf("ID: %d, Name: %s, Complete: %s\n", tasks[i].id, tasks[i].name, tasks[i].complete ? "Yes" : "No");
        }
      }
    }

    if (strcmp(cmd, "/newTask") == 0)
    {
      char firstChar[1];
      char name[100];

      printf("\nEnter the name of the task:\n");
      scanf(" %s", &firstChar);
      fgets(name, 100, stdin);
      strcat(firstChar, name);
      firstChar[strcspn(firstChar, "\n")] = '\0';
      tasks[lastId].id = lastId + 1;
      strcpy(tasks[lastId].name, firstChar);
      tasks[lastId].complete = false;
      lastId++;
    }

    if (strcmp(cmd, "/deleteTask") == 0)
    {
      int id;
      printf("\nEnter the id of the task:\n");
      scanf(" %d", &id);
      for (int i = 0; i < 100; i++)
      {
        if (tasks[i].id == id)
        {
          tasks[i].id = 0;
        }
      }
    }

    if (strcmp(cmd, "/toggleCompletion") == 0)
    {
      int id;
      printf("\nEnter the id of the task:\n");
      scanf(" %d", &id);
      for (int i = 0; i < 100; i++)
      {
        if (tasks[i].id == id)
        {
          tasks[i].complete = !tasks[i].complete;
        }
      }
    }
  }
}
