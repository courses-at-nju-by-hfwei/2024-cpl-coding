# `13-linked-list`

- CMakeLists.txt (`ll/ll.c`)
- `struct node *`
- `#ifndef`

## Intrusive list

- [Data Structures in the Linux Kernel: Doubly linked list](https://0xax.gitbooks.io/linux-insides/content/DataStructures/linux-datastructures-1.html)
  - [types.h](https://github.com/torvalds/linux/blob/16f73eb02d7e1765ccab3d2018e0bd98eb93d973/include/linux/types.h)
    - [list_head](https://github.com/torvalds/linux/blob/16f73eb02d7e1765ccab3d2018e0bd98eb93d973/include/linux/types.h#L184)
  - [list.h](https://github.com/torvalds/linux/blob/16f73eb02d7e1765ccab3d2018e0bd98eb93d973/include/linux/list.h)
  - [misc.c as an application](https://github.com/torvalds/linux/blob/16f73eb02d7e1765ccab3d2018e0bd98eb93d973/drivers/char/misc.c)

```c++
struct list_head {
	struct list_head *next, *prev;
};
```

## [linux](https://github.com/torvalds/linux)

- [types.h](https://github.com/torvalds/linux/blob/16f73eb02d7e1765ccab3d2018e0bd98eb93d973/include/linux/types.h)
  - [list_head](https://github.com/torvalds/linux/blob/16f73eb02d7e1765ccab3d2018e0bd98eb93d973/include/linux/types.h#L184)
- [list.h](https://github.com/torvalds/linux/blob/16f73eb02d7e1765ccab3d2018e0bd98eb93d973/include/linux/list.h)
- [How does the kernel implements Linked Lists?](https://kernelnewbies.org/FAQ/LinkedLists)
  > Also illustrate how to use the list_head structure.

## [`GList`](https://gitlab.gnome.org/GNOME/glib/-/blob/bc56578a087fc4eda0204b361d75162a4144546d/glib/glist.c) in

`GNOME/glibc`

- [glist.h](https://gitlab.gnome.org/GNOME/glib/-/blob/main/glib/glist.h)
- [glist.c](https://gitlab.gnome.org/GNOME/glib/-/blob/main/glib/glist.c)

```c++
typedef struct _GList GList;

struct _GList
{
  gpointer data;
  GList *next;
  GList *prev;
};
```

- [Docs for List](https://docs.gtk.org/glib/struct.List.html)

## `glibc`

- [list_t.h](https://github.com/bminor/glibc/blob/master/include/list_t.h)
- [list.h](https://github.com/bminor/glibc/blob/master/include/list.h)