#include "ft_ls.h"

int check_valid_option(char *str, int result)
{
    /* 0-й символ уже '-' */
    int i;
    int index;

    i = 1;
    index = 0;
    if ((str[i] == '-') && (!(str[i + 1])))
        return (0); // это норм, флаг '--' валидный, возвращаем нолик
    while(str[i])
    {
        if (!(ft_strchr(OPTIONS, str[i])))
        {
            write(1, "illegal option -- ", 18);
            write(1, &str[i], 1);
            write(1, "\n", 1);
            write(1, "usage: ls [-ACLOPRST@adefhiklmnoprst1] [file ...]\n", 50);
            return (-1); // инвалидный флаг
        }
        else {
//			for (int z = 0; z < 100 && OPTIONS[z] != str[i]; z++)
//				index = 31 - (z + 1 + OPTIONS_SHIFT); //
//			// как i
//			printf("eto index %d\n", index);
//			if (!((result >> (31 - index)) & 1));
//				result += (1 << (index));
//				result += (1 << (index));

//            for (int z = 0; z < 100 && OPTIONS[z] != str[i]; z++)
//                index = z + 1;

            //printf("eto index %d\n", index);

            index = (ft_strchr(OPTIONS, str[i])) - str;
            if (index == 1)
            {
                result &= ~(1 << 24 | 1 << 16);
                //printf("О нихуя\n");
            }

            else if (index == 16)
                result &= ~(1 << 1 | 1 << 24);
            else if (index == 24)
                result &= ~(1 << 1 | 1 << 16);
            else if (index == 2)
                result &= ~(1 << 4);
            else if (index == 4)
                result &= ~(1 << 2);
            if (!((result >> index) & 1))
                result += (1 << (index));
            //100000000000000001
            //"ACLOPRST@adefhiklmnoprst1"


            printf("result: %d\n", result);
            //printf("the letter was: %c\n", str[i]);
            i++;
        }
    }
    return (result);
}

int check_file(char *str)
{
    int a = 0;
    DIR *dir;
    struct dirent *ent;
    struct stat buf;

    if (ft_strlen(str) > 255)
    {
        write(1, "ls: ", 4);
        ft_putstr(str);
        write (1, ": File name too long\n", 20);
    }
    if ((dir = opendir (str)) != NULL)
    {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            //printf ("file or dir: ");
            //ft_putstr(ent->d_name);
            writing_file_data(ent->d_name);
            // и здесь кастовать lstat на file_name;
            write(1, "\n", 1);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        if ((a = lstat(str, &buf)) == -1) // а здесь вызывается функция, которая пишет в список
        {
            write(1, "ls: ", 4);
            ft_putstr(str);
            write(1, ": No such file or directory\n", 28);
            return EXIT_FAILURE;
        }
        else
            printf("Нашел файлик!: %s\n", str);
    }
    return (0);

}

int validation(int argc, char *argv[])
{
    int j;
    int result = 0;

    j = 0;
    if (argc > 1)
    {
        argc -= 1;
        while (argc > 0) {

//			while (argv[argc])
//			{
            if (argv[argc][0] == '-')
            {
                if (!(argv[argc][1])) {
                    write(1, "ls: -: No such file or directory\n", 33);
                    return(-1);
                }
                if ((result = (check_valid_option(argv[argc], result))) == -1) // если есть -, значит это флаг. Отправляемся проверять его валидность. Если возвращает -1, выходим, else return options;
                    return (-1);
            }
            else
                check_file(argv[argc]); // если минуса нет, значит это файл, и надо проверять его валидность. Дальше в мейне сделать проверку на отсутствие файла.
            argc--;
//			}
        }
        return (result);
    }
    return (0);
}

