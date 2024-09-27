add_executable(circle circle.c)

add_executable(sphere sphere.c)
target_link_libraries(sphere m)

add_executable(mol mol.c)

add_executable(admin admin.c)
target_link_libraries(admin m)

add_executable(admin-final admin-final.c)
target_link_libraries(admin-final m)

add_executable(admin-scanf admin-scanf.c)
target_link_libraries(admin-scanf m)

add_executable(admin-scanf-final admin-scanf-final.c)
target_link_libraries(admin-scanf-final m)

add_executable(printf-error printf-error.c)
add_executable(scanf-error scanf-error.c)

add_executable(scanf-c17-ex2 scanf-c17-ex2.c)
add_executable(scanf-c17-ex3 scanf-c17-ex3.c)