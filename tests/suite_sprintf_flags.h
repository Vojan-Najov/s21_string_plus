#ifndef SUITE_SPRINTF_FLAGS_H
#define SUITE_SPRINTF_FLAGS_H

/*
static const char *two_char_format[] = {
        "_%c__%10c_\n",
        "_%-c__%-10c_\n",
        "_%+c__%10c_\n",
        "_% c__%-10c_\n",
        "_%#c__%10c_\n",
        "_%0c__%-10c_\n",
        "_%64c__%10c_\n",
        "_%-64c__%-10c_\n",
        "_%+64c__%10c_\n",
        "_% 64c__%-10c_\n",
        "_%#64c__%10c_\n",
        "_%064c__%-10c_\n",
        "_%-+64c__%10c_\n",
        "_%- 64c__%-10c_\n",
        "_%-#64c__%10c_\n",
        "_%-064c__%-10c_\n",
        "_%-+ #064c__%10c_\n",
        NULL
};
*/

static const char *sprintf_flags[] = {
    "",     "-",    "+",    " ",    "#",    "0",    "-+",   "- ",   "-#",
    "-0",   "+-",   "+ ",   "+#",   "+0",   " -",   " +",   " #",   " 0",
    "#-",   "#+",   "# ",   "#0",   "0-",   "0+",   "0 ",   "0#",   "-+ ",
    "-+#",  "-+0",  "- +",  "- #",  "- 0",  "-#+",  "-# ",  "-#0",  "-0+",
    "-0 ",  "-0#",  "+- ",  "+-#",  "+-0",  "+ -",  "+ #",  "+ 0",  "+#-",
    "+# ",  "+#0",  "+0-",  "+0 ",  "+0#",  " -+",  " -#",  " -0",  " +-",
    " +#",  " +0",  " #-",  " #+",  " #0",  " 0-",  " 0+",  " 0#",  "#-+",
    "#- ",  "#-0",  "#+-",  "#+ ",  "#+0",  "# -",  "# +",  "# 0",  "#0-",
    "#0+",  "#0 ",  "0-+",  "0- ",  "0-#",  "0+-",  "0+ ",  "0+#",  "0 -",
    "0 +",  "0 #",  "0#-",  "0#+",  "0# ",  "-+ #", "-+ 0", "-+# ", "-+#0",
    "-+0 ", "-+0#", "- +#", "- +0", "- #+", "- #0", "- 0+", "- 0#", "-#+ ",
    "-#+0", "-# +", "-# 0", "-#0+", "-#0 ", "-0+ ", "-0+#", "-0 +", "-0 #",
    "-0#+", "-0# ", "+- #", "+- 0", "+-# ", "+-#0", "+-0 ", "+-0#", "+ -#",
    "+ -0", "+ #-", "+ #0", "+ 0-", "+ 0#", "+#- ", "+#-0", "+# -", "+# 0",
    "+#0-", "+#0 ", "+0- ", "+0-#", "+0 -", "+0 #", "+0#-", "+0# ", " -+#",
    " -+0", " -#+", " -#0", " -0+", " -0#", " +-#", " +-0", " +#-", " +#0",
    " +0-", " +0#", " #-+", " #-0", " #+-", " #+0", " #0-", " #0+", " 0-+",
    " 0-#", " 0+-", " 0+#", " 0#-", " 0#+", "#-+ ", "#-+0", "#- +", "#- 0",
    "#-0+", "#-0 ", "#+- ", "#+-0", "#+ -", "#+ 0", "#+0-", "#+0 ", "# -+",
    "# -0", "# +-", "# +0", "# 0-", "# 0+", "#0-+", "#0- ", "#0+-", "#0+ ",
    "#0 -", "#0 +", "0-+ ", "0-+#", "0- +", "0- #", "0-#+", "0-# ", "0+- ",
    "0+-#", "0+ -", "0+ #", "0+#-", "0+# ", "0 -+", "0 -#", "0 +-", "0 +#",
    "0 #-", "0 #+", "0#-+", "0#- ", "0#+-", "0#+ ", "0# -", "0# +", "-+ 0#",
    NULL};

#endif
