#include <iostream>
extern "C" {
#include "mongoose.h"
}

static void fn(struct mg_connection* c, int ev, void* ev_data, void* fn_data) {
    if (ev == MG_EV_HTTP_MSG) {
        struct mg_http_message* hm = (struct mg_http_message*)ev_data;
        if (mg_http_match_uri(hm, "/helloworld")) {
            mg_http_reply(c, 200, "", "helloworld");
        }
    }
    (void)fn_data;
}

int main() {
    // Initialise event manager
    struct mg_mgr mgr;
    mg_mgr_init(&mgr);

    // Create HTTP listener
    mg_http_listen(&mgr, "http://0.0.0.0:50000", fn, NULL);

    // Infinite event loop
    while(true) {
        mg_mgr_poll(&mgr, 1000);
    }

    return 0;
}
