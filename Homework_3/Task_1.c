#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// ¡Hala Madrid! Настраиваем нашу команду заголовков
int main(int argc, char *argv[]) {
    // ¡Vamos Blanco! Проверяем, пришлись ли аргументы по форме
    if (argc != 4) {
        fprintf(stderr, "Использование: %s <шаблон_REGEX> <текст> <замена>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Задаём стартовый состав: паттерн, текст, замена
    const char *pattern     = argv[1]; // Наш главный тренер — регулярка
    const char *input_text  = argv[2]; // Поле битвы — исходный текст
    const char *replacement = argv[3]; // Голевая замена

    // Составляем regex: точный выбор игроков
    regex_t regex;
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Упс! Не удалось собрать regex '%s' — тренер разозлился!\n", pattern);
        return EXIT_FAILURE;
    }

    // ¡Al Bernabéu! Выделяем буфер под результат (как трибуна под болельщиков)
    size_t cap = strlen(input_text) + 1;
    char *result = malloc(cap);
    if (!result) {
        perror("Ошибка выделения памяти");
        regfree(&regex);
        return EXIT_FAILURE;
    }
    size_t len = 0;
    result[0] = '\0'; // Начинаем с чистого листа, как стартовый матч

    const char *cursor = input_text;
    regmatch_t pmatch[1];

    // ¡A por ellos! Ищем и заменяем — как забиваем голы подряд
    while (regexec(&regex, cursor, 1, pmatch, 0) == 0) {
        size_t prefix   = pmatch[0].rm_so;    // Часть перед матчем
        size_t repl_len = strlen(replacement); // Размер гола

        // Динамически расширяем стадион, если болельщиков больше, чем ожидалось
        size_t needed = len + prefix + repl_len + 1;
        if (needed > cap) {
            cap   = needed * 2;
            char *tmp = realloc(result, cap);
            if (!tmp) {
                perror("Ошибка перераспределения памяти");
                free(result);
                regfree(&regex);
                return EXIT_FAILURE;
            }
            result = tmp;
        }

        // Копируем до вхождения — как первые трибуны
        memcpy(result + len, cursor, prefix);
        len += prefix;

        // Вставляем замену — как празднуем гол в стиле "¡Hala Madrid!"
        memcpy(result + len, replacement, repl_len);
        len += repl_len;
        result[len] = '\0';

        // Продвигаем курсор дальше — как мяч летит в штрафную соперника
        cursor += pmatch[0].rm_eo;
    }

    // Остаток текста — финальные минуты добавленного времени
    size_t rem = strlen(cursor);
    if (len + rem + 1 > cap) {
        char *tmp = realloc(result, len + rem + 1);
        if (!tmp) {
            perror("Ошибка перераспределения памяти");
            free(result);
            regfree(&regex);
            return EXIT_FAILURE;
        }
        result = tmp;
    }
    strcpy(result + len, cursor);

    // ¡Final del partido! Выводим результат в эфир, трибуны аплодируют
    fputs(result, stdout);
    fputc('\n', stdout);

    // Сезон закончен: очищаем лавку и отдаем регламент обратно в клуб
    free(result);
    regfree(&regex);
    return EXIT_SUCCESS;
}
