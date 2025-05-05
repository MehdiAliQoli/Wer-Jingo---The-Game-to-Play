//#include <iostream>
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_primitives.h>
//
//const int INITIAL_W = 1900;
//const int INITIAL_H = 950;
//const double FPS = 60.0;
//
//int main() {
//    // 1) Core init
//    if (!al_init()) {
//        std::cerr << "al_init() failed\n";
//        return -1;
//    }
//
//    // 2) Primitives addon (for drawing)
//    if (!al_init_primitives_addon()) {
//        std::cerr << "al_init_primitives_addon() failed\n";
//        return -1;
//    }
//
//    // 3) Enable resizable windows (must be before creating the display)
//    al_set_new_display_flags(ALLEGRO_RESIZABLE);
//
//    // 4) Create the display
//    ALLEGRO_DISPLAY* disp = al_create_display(INITIAL_W, INITIAL_H);
//    if (!disp) {
//        std::cerr << "al_create_display() failed\n";
//        return -1;
//    }
//
//    // 5) Create a 60 FPS timer
//    ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
//    if (!timer) {
//        std::cerr << "al_create_timer() failed\n";
//        al_destroy_display(disp);
//        return -1;
//    }
//
//    // 6) Event queue
//    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
//    if (!queue) {
//        std::cerr << "al_create_event_queue() failed\n";
//        al_destroy_timer(timer);
//        al_destroy_display(disp);
//        return -1;
//    }
//
//    // 7) Register display and timer events
//    al_register_event_source(queue, al_get_display_event_source(disp));
//    al_register_event_source(queue, al_get_timer_event_source(timer));
//
//    // 8) Start the timer
//    al_start_timer(timer);
//
//    bool running = true;
//    bool redraw = false;
//    double scale = 1.0; // Initial scale factor
//
//    int new_width;
//    int new_height;
//
//    // 9) Main loop
//    while (running) {
//        ALLEGRO_EVENT ev;
//        al_wait_for_event(queue, &ev);
//
//        switch (ev.type) {
//        case ALLEGRO_EVENT_DISPLAY_CLOSE:
//            running = false;
//            break;
//
//        case ALLEGRO_EVENT_DISPLAY_RESIZE:
//            // Get the new width and height of the window
//            new_width = ev.display.width;
//            new_height = ev.display.height;
//
//            // Update the scale based on the new window size
//            scale = std::min((double)new_width / INITIAL_W, (double)new_height / INITIAL_H);
//            // A simple scaling logic: scale based on the smaller dimension (aspect ratio is preserved)
//            al_acknowledge_resize(disp);
//            break;
//
//        case ALLEGRO_EVENT_TIMER:
//            redraw = true;
//            break;
//
//        default:
//            break;
//        }
//
//        if (redraw && al_is_event_queue_empty(queue)) {
//            redraw = false;
//
//            // Clear to black
//            al_clear_to_color(al_map_rgb(0, 0, 0));
//
//            // Scale the position and size of the rectangle
//            // Original rectangle size: 100x100 (at position 100, 100)
//            int x = 100 * scale;
//            int y = 100 * scale;
//            int w = 100 * scale;
//            int h = 100 * scale;
//
//            // Draw a scaled red rectangle
//            al_draw_filled_rectangle(x, y, x + w, y + h, al_map_rgb(255, 0, 0));
//
//            // Show it
//            al_flip_display();
//        }
//    }
//
//    // 10) Cleanup
//    al_destroy_event_queue(queue);
//    al_destroy_timer(timer);
//    al_destroy_display(disp);
//    al_shutdown_primitives_addon();
//
//    return 0;
//}
