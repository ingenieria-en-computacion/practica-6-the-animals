#include <stdio.h>
#include <check.h>
#include "cola_circular.h"
#include "bicola.h"

START_TEST(test_cola_crear) {
    ColaCircular cola;
    cola_crear(&cola);
    ck_assert_int_eq(cola_vacia(&cola), 1);
}

START_TEST(test_bicola_agregar_frente) {
    Bicola bi;
    bicola_crear(&bi);
    bicola_agregar_frente(&bi, 10);
    ck_assert_int_eq(bicola_eliminar_frente(&bi), 10);
}

Suite* cola_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("Cola");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_cola_crear);
    suite_add_tcase(s, tc_core);

    return s;
}

Suite* bicola_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("Bicola");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_bicola_agregar_frente);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    printf("Ejecutando pruebas unitarias:\n");
    int number_failed;
    Suite* s;
    SRunner* sr;

    s = cola_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    s = bicola_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);

    printf("Número de pruebas fallidas: %d\n", number_failed);
    return (number_failed == 0) ? 0 : 1;
}
