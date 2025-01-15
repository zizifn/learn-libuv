#include <uv.h>
#include <stdio.h>

void check_cb(uv_check_t *handle)
{
    static int check_counter = 0;
    check_counter += 1;
    printf("Check callback #%d\n", check_counter);
    uv_check_stop(handle); // Stop the check handle// Stop the event loop after the check callback
}

void idle_cb(uv_idle_t *handle)
{
    static int idle_counter = 0;
    idle_counter += 1;
    printf("Idle callback #%d", idle_counter);
    uv_idle_stop(handle); 
}

int main()
{
    uv_loop_t *loop = uv_default_loop();
    uv_check_t check_handle;
    uv_idle_t idle_handle;

    // Initialize and start check handle
    uv_check_init(loop, &check_handle);
    uv_check_start(&check_handle, check_cb);
    // uv_unref((uv_handle_t*) &check_handle);

    // Initialize and start idle handle
    uv_idle_init(loop, &idle_handle);
    uv_idle_start(&idle_handle, idle_cb);

    printf("Starting event loop\n");
    uv_run(loop, UV_RUN_DEFAULT); // Run the event loop
    printf("Event loop stopped\n");

    uv_loop_close(loop); // Close the loop after it finishes
    return 0;
}
