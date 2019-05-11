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

            index = (ft_strchr(OPTIONS, str[i])) - OPTIONS;
            //printf("a vot возврат strchr %s\n", ft_strchr(OPTIONS, str[i]));
            if (index == 1)
            {
                result &= ~(1 << 24 | 1 << 16); // тогда выключаем биты
//                printf("Здесь C\n");
            }

            else if (index == 16)
            {
                result &= ~(1 << 1 | 1 << 24);
//                printf("здесь l\n");
            }

            else if (index == 24)
            {
                result &= ~(1 << 1 | 1 << 16);
//                printf("здесь 1\n");
            }

            else if (index == 2)
            {
                result &= ~(1 << 4);
                printf("здесь L\n");
            }

            else if (index == 4)
            {
                result &= ~(1 << 2);
                printf("здесь P\n");
            }
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

int check_file(char *str, int result)
{
    int a = 0;
    DIR *dir;
    char *d_name;
    struct dirent *ddir;
    struct stat buf;
    int i = 0;
    if (ft_strlen(str) > 255)
    {
        write(1, "ls: ", 4);
        ft_putstr(str);
        write (1, ": File name too long\n", 20);
    }
    if ((dir = opendir (str)) != NULL)
    {
        /* print all the files and directories within directory */
        while ((ddir = readdir (dir)) != NULL)
        {
            d_name = ft_strdup(ddir->d_name);
                //(d_name = ft_strdup(readdir (dir)->d_name)) != NULL)
                 // в этом цикле очень дохуя вертится
//            printf ("file or dir: \n"); // тут надо замаллочить под структуру, нужно только ent -> d_name
//            ft_putstr(ent->d_name); // ent -> d_name содержит имена всех файлов и папок
            printf ("\n");
            if ((result >> 16) & 1) // здесь для формата long
            {
                printf("%d\n", i++);
                printf("here's something long\n");
                writing_file_data_long_dir(d_name, str, result);
            }
            else
                writing_file_data_dir(d_name, str, result);
            write(1, "\n", 1);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        if ((a = lstat(str, &buf)) == -1) // а здесь вызывается функция, которая пишет в
        {
            write(1, "ls: ", 4);
            ft_putstr(str);
            write(1, ": No such file or directory\n", 28);
            return EXIT_FAILURE;
        }
        else if ((result >> 16) & 1)
        {
            printf("Нашел файлик в формате long!: %s\n", str);
            writing_file_data_long(str, result);
        }
        else
        {
            printf("Нашел файлик!: %s\n", str);
            writing_file_data(str, result);
        }
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
        while (++j < argc) {

            if (argv[j][0] == '-')
            {
                result = (check_valid_option(argv[j], result)); // not sure if it's not going to break valid
                if (!(argv[j][1])) {
                    write(1, "ls: -: No such file or directory\n", 33);
                    return(-1);
                }
                if (result == -1) // если есть -, значит это флаг. Отправляемся проверять его валидность. Если возвращает -1, выходим, else return options;
                    return (-1);
            }
            else
                check_file(argv[j], result); // если минуса нет, значит это файл, и надо проверять его валидность. Дальше в мейне сделать проверку на отсутствие файла.
        }
        return (result);
    }
    return (0);
}

