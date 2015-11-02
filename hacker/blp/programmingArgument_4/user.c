/*
 * =====================================================================================
 *
 *       Filename:  user.c
 *
 *    Description:  get user info
 *
 *        Version:  1.0
 *        Created:  08/19/2015 04:28:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    uid_t uid;
    gid_t gid;

    struct passwd *pw;
    uid = getuid();
    gid = getgid();

    printf("User is %s\n", getlogin());

    printf("User IDs: uid = %d, gid = %d\n", uid, gid);

    pw = getpwuid(uid);
    printf("UID passwd entry : \nname = %s, uid = %d, gid = %d, home = %s, shell = %s\n", 
            pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);

    pw = getpwnam("root");
    printf("root passwd entry\n");
    printf("name = %s, uid = %d, gid = %d, home = %s, shell = %s\n", 
            pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);

    return 0;
}
