#include <yed/plugin.h>

static void        unload(yed_plugin *self);
static yed_buffer *get_or_make_buff(void);

int yed_plugin_boot(yed_plugin *self) {
    YED_PLUG_VERSION_CHECK();

    yed_plugin_set_unload_fn(self, unload);

    get_or_make_buff();

    return 0;
}

static void unload(yed_plugin *self) {
    yed_buffer *buff;

    buff = yed_get_buffer("*git-gui");
    if (buff != NULL) {
        yed_free_buffer(buff);
    }
}

static yed_buffer *get_or_make_buff(void) {
    yed_buffer *buff;

    buff = yed_get_buffer("*git-gui");

    if (buff == NULL) {
        buff = yed_create_buffer("*git-gui");
        buff->flags |= BUFF_SPECIAL;
        yed_buffer_add_line(buff);
        yed_buff_insert_string(buff, "      ___                       ___                    ___           ___                  ", 1, 1);
        yed_buff_insert_string(buff, "     /\\  \\          ___        /\\  \\                  /\\  \\         /\\__\\          ___  ", 2, 1);
        yed_buff_insert_string(buff, "    /::\\  \\        /\\  \\       \\:\\  \\                /::\\  \\       /:/  /         /\\  \\   ", 3, 1);
        yed_buff_insert_string(buff, "   /:/\\:\\  \\       \\:\\  \\       \\:\\  \\     ___      /:/\\:\\  \\     /:/  /          \\:\\  \\  ", 4, 1);
        yed_buff_insert_string(buff, "  /:/  \\:\\  \\      /::\\__\\      /::\\  \\   /\\__\\    /:/  \\:\\  \\   /:/  /  ___      /::\\__\\ ", 5, 1);
        yed_buff_insert_string(buff, " /:/__/_\\:\\__\\  __/:/\\/__/     /:/\\:\\__\\  \\/__/   /:/__/_\\:\\__\\ /:/__/  /\\__\\  __/:/\\/__/ ", 6, 1);
        yed_buff_insert_string(buff, " \\:\\  /\\ \\/__/ /\\/:/  /       /:/  \\/__/          \\:\\  /\\ \\/__/ \\:\\  \\ /:/  / /\\/:/  /    ", 7, 1);
        yed_buff_insert_string(buff, "  \\:\\ \\:\\__\\   \\::/__/       /:/  /                \\:\\ \\:\\__\\    \\:\\  /:/  /  \\::/__/     ", 8, 1);
        yed_buff_insert_string(buff, "   \\:\\/:/  /    \\:\\__\\       \\/__/                  \\:\\/:/  /     \\:\\/:/  /    \\:\\__\\     ", 9, 1);
        yed_buff_insert_string(buff, "    \\::/  /      \\/__/                               \\::/  /       \\::/  /      \\/__/     ", 10, 1);
        yed_buff_insert_string(buff, "     \\/__/                                            \\/__/         \\/__/                 ", 11, 1);
    }

    return buff;
}
