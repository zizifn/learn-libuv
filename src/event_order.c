#include <uv.h>
#include <stdio.h>

static int check_counter = 0;
static int prepare_counter = 0;

static void check_cb(uv_check_t* handle) {
    check_counter++;
    printf("Check callback #%d\n", check_counter);
}

static void prepare_cb(uv_prepare_t* handle) {
    prepare_counter++;
    printf("Prepare callback #%d\n", prepare_counter);
}

int main() {
    uv_loop_t *loop = uv_default_loop();

    uv_check_t check_req;
    uv_prepare_t prepare_req;

    uv_check_init(loop, &check_req);
    uv_check_start(&check_req, check_cb);

    // uv_prepare_init(loop, &prepare_req);
    // uv_prepare_start(&prepare_req, prepare_cb);

    printf("Before uv_run\n");
    uv_run(loop, UV_RUN_DEFAULT);
    printf("After uv_run\n");

    uv_prepare_stop(&prepare_req);
    uv_check_stop(&check_req);

    uv_loop_close(loop);
    return 0;
}
