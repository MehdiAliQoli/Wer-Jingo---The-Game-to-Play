#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<allegro5/allegro_video.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "WerJingo.h"
#include<math.h>
#include<typeinfo>
#include<chrono>
#include<thread>



void showInstruction(ALLEGRO_FONT* font) {
    // Clear background and draw semi-transparent box
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_filled_rounded_rectangle(200, 100, 1500, 800, 20, 20, al_map_rgba(0, 0, 0, 180));

    // Title
    al_draw_text(font, al_map_rgb(255, 215, 0), 850, 120, ALLEGRO_ALIGN_CENTER, "-> CONTROLS & SKILLS <-");

    // Instructions
    int x = 280;
    int y = 200;
    int spacing = 50;

    al_draw_text(font, al_map_rgb(255, 255, 255), x, y + spacing * 0, 0, "W  - Jump");
    al_draw_text(font, al_map_rgb(255, 255, 255), x, y + spacing * 1, 0, "A  - Move Left");
    al_draw_text(font, al_map_rgb(255, 255, 255), x, y + spacing * 2, 0, "D  - Move Right");
    al_draw_text(font, al_map_rgb(255, 255, 255), x, y + spacing * 3, 0, "J  - Normal Attack");
    al_draw_text(font, al_map_rgb(255, 255, 255), x, y + spacing * 4, 0, "K  - Block (Takes no damage while holding)");
    al_draw_text(font, al_map_rgb(255, 255, 255), x, y + spacing * 5, 0, "L  - Dash (Sprints and attacks)");

    al_draw_text(font, al_map_rgb(255, 255, 255), x, y + spacing * 6, 0, "U  - Skill1 (If falling, crashes down damaging enemies in AOE)");
    al_draw_text(font, al_map_rgb(255, 255, 255), x, y + spacing * 7, 0, "I  - Skill2 (Pushes away and damages enemies while moving)");
    al_draw_text(font, al_map_rgb(255, 255, 255), x, y + spacing * 8, 0, "O  - Ult Skill (2.5 sec of invincible rapid attacks)");

    // Close hint
 /*   al_draw_text(font, al_map_rgb(180, 180, 180), 850, y + spacing * 10, ALLEGRO_ALIGN_CENTER, "Press 'I' to close");*/

    // Display
    al_flip_display();
}

void showHelp(ALLEGRO_FONT* font) {
    // Clear screen and draw background
    al_clear_to_color(al_map_rgb(30, 30, 30));
    al_draw_filled_rounded_rectangle(200, 200, 1700, 700, 25, 25, al_map_rgba(0, 0, 0, 180));

    // Title
    al_draw_text(font, al_map_rgb(255, 215, 0), 960, 220, ALLEGRO_ALIGN_CENTER, "HELP & SUPPORT");

    // Help content
    int y = 300;
    int spacing = 60;

    al_draw_text(font, al_map_rgb(255, 255, 255), 960, y, ALLEGRO_ALIGN_CENTER,
        "-> If you're facing any issue or want to give suggestions,");
    y += spacing;
    al_draw_text(font, al_map_rgb(255, 255, 255), 960, y, ALLEGRO_ALIGN_CENTER,
        "   feel free to reach out to Team Werjingo at:");
    y += spacing;
    al_draw_text(font, al_map_rgb(173, 216, 230), 960, y, ALLEGRO_ALIGN_CENTER,
        "   warjingo131@gmail.com");

    // Tip to close
    y += spacing * 2;
    al_draw_text(font, al_map_rgb(180, 180, 180), 960, y, ALLEGRO_ALIGN_CENTER,
        "Press 'Esc' to go back");

    // Flip display to show content
    al_flip_display();
}

void showDevelopers(ALLEGRO_FONT* font, ALLEGRO_BITMAP* mehdi, ALLEGRO_BITMAP* ismail, ALLEGRO_BITMAP* Qadrain, ALLEGRO_BITMAP* ismail2) {
    al_draw_filled_rounded_rectangle(200, 300, 1500, 600, 20, 20, al_map_rgba(0, 0, 0, 180));

    // Title (golden color)
    al_draw_text(font, al_map_rgb(255, 215, 0), 1000, 420, ALLEGRO_ALIGN_CENTER, "->Team Werjingo<-");
    al_clear_to_color(al_map_rgb(255, 255, 255));
    // Inventory items (white text)
    int item_y_start = 200;
    int line_spacing = 100;
    int orignal_w = al_get_bitmap_width(mehdi);


    al_draw_bitmap(ismail, 450, 100, 0);
    al_draw_bitmap(mehdi, 450, 500, 0);
    al_draw_bitmap(Qadrain, 1400, 100, 0);
    al_draw_bitmap(ismail2, 1400, 500, 0);




    al_draw_text(font, al_map_rgb(50, 200, 0), 500, 800, ALLEGRO_ALIGN_CENTER, "-> M e h d i  A l i  3 0 5 0 7");
    al_draw_text(font, al_map_rgb(50, 200, 0), 500, 400, ALLEGRO_ALIGN_CENTER, " -> M u h a m m a d  I s m a i l  3 0 9 1 7");

    al_draw_text(font, al_map_rgb(50, 200, 0), 1400, 400, ALLEGRO_ALIGN_CENTER, "-> Q a d r a i n  Q a d i r  3 0 5 7 1");
    al_draw_text(font, al_map_rgb(50, 200, 0), 1400, 800, ALLEGRO_ALIGN_CENTER, " -> M u h a m m a d  I s m a i l 3 1 6 8 9");
    // Hint to close (gray text)


    // Flip display (draw everything)
    al_flip_display();

};

bool s1a = false;
bool s2a = false;
bool s3a = false;
void showInventory(ALLEGRO_FONT* font) {
    // Dark transparent background (semi-transparent black box)
    al_draw_filled_rounded_rectangle(500, 150, 1500, 800, 20, 20, al_map_rgba(0, 0, 0, 180));

    // Title (golden color)
    al_draw_text(font, al_map_rgb(255, 215, 0), 1000, 180, ALLEGRO_ALIGN_CENTER, "INVENTORY");

    // Inventory items (white text)
    int item_y_start = 260;
    int line_spacing = 60;

    al_draw_text(font, al_map_rgb(255, 255, 255), 1000, item_y_start, ALLEGRO_ALIGN_CENTER, "- Skill 1: Attack");
    al_draw_text(font, al_map_rgb(255, 255, 255), 1000, item_y_start + line_spacing, ALLEGRO_ALIGN_CENTER, "- Skill 2: Block");
    al_draw_text(font, al_map_rgb(255, 255, 255), 1000, item_y_start + line_spacing*2, ALLEGRO_ALIGN_CENTER, "- Skill 3: Dash");
    if (s1a)
    al_draw_text(font, al_map_rgb(255, 255, 255), 1000, item_y_start + line_spacing*3, ALLEGRO_ALIGN_CENTER, "- Skill 4: Crash Down");
    if (s2a)
    al_draw_text(font, al_map_rgb(255, 255, 255), 1000, item_y_start + line_spacing*4, ALLEGRO_ALIGN_CENTER, "- Skill 5: Push Bacl");
    if (s3a)
    al_draw_text(font, al_map_rgb(255, 255, 255), 1000, item_y_start + line_spacing*5, ALLEGRO_ALIGN_CENTER, "- Skill 6: Consecutive Strike");

    // Hint to close (gray text)
    al_draw_text(font, al_map_rgb(180, 180, 180), 1000, 700, ALLEGRO_ALIGN_CENTER, "Press 'M' to close");

    // Flip display (draw everything)
    al_flip_display();
}

void showlvl(ALLEGRO_FONT* font, int n) {
  

    al_draw_text(font, al_map_rgb(255, 215, 0), 940, 442, ALLEGRO_ALIGN_CENTER, ("Level Up !! " + to_string(n)).c_str());

    al_flip_display();
    this_thread::sleep_for(chrono::seconds(2));
}

void showskil(ALLEGRO_FONT* font) {


    al_draw_text(font, al_map_rgb(0, 215, 0), 940, 442, ALLEGRO_ALIGN_CENTER, ("New Skill Achieved, Check Inventory"));

    al_flip_display();
    this_thread::sleep_for(chrono::seconds(1));
}
void gameover(ALLEGRO_FONT* font) {


    al_draw_text(font, al_map_rgb(112, 0, 255), 940, 442, ALLEGRO_ALIGN_CENTER, ("You Died! Try again"));

    al_flip_display();
    this_thread::sleep_for(chrono::seconds(3));
}


void draw_menu(int& selected_option, ALLEGRO_FONT* font, ALLEGRO_FONT* font2, int display_width, int display_height, float time) {
    al_clear_to_color(al_map_rgb(15, 15, 30)); // Clear screen with background color

    // Draw title
    al_draw_text(font, al_map_rgb(173, 216, 230), 1000, 250, ALLEGRO_ALIGN_CENTRE, "WerJinGO");

    const vector<string> options = { "Start Game", "Instruction","Help" , "Developers Profile" , "Exit" };
    int total_options = options.size();
    int menu_start_y = display_height / 2 - 120;
    int line_spacing = 90;

    for (int i = 0; i < total_options; ++i) {
        bool is_selected = (i == selected_option);

        float pulse = 0.5f + 0.5f * sin(time * 4);  // Pulsing effect
        ALLEGRO_COLOR color = is_selected
            ? al_map_rgb(255, static_cast<int>(255 * pulse), 100)
            : al_map_rgb(200, 200, 200);

        string arrow = is_selected ? "-> " : "   ";

        // Text shadow
        al_draw_textf(font, al_map_rgb(0, 0, 0), 940 + 2, menu_start_y + i * line_spacing + 2,
            ALLEGRO_ALIGN_CENTRE, "%s%s", arrow.c_str(), options[i].c_str());

        // Menu option
        al_draw_textf(font, color, 940, menu_start_y + i * line_spacing,
            ALLEGRO_ALIGN_CENTRE, "%s%s", arrow.c_str(), options[i].c_str());
    }

    al_flip_display(); // Display all the drawn content
}






bool Story(const char* videoPath, ALLEGRO_DISPLAY* display) {
    // Check if the display is valid
    if (!display) {
        std::cerr << "Error: Invalid display" << std::endl;
        return false;
    }

    // Create an event queue for handling events
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    if (!queue) {
        std::cerr << "Error: Failed to create event queue" << std::endl;
        return false;
    }

    // Make sure Allegro Video addon is initialized
    if (!al_is_video_addon_initialized()) {
        if (!al_init_video_addon()) {
            std::cerr << "Error: Failed to initialize video addon" << std::endl;
            al_destroy_event_queue(queue);
            return false;
        }
    }

    // Load the video
    ALLEGRO_VIDEO* video = al_open_video(videoPath);
    if (!video) {
        std::cerr << "Error: Failed to open video file: " << videoPath << std::endl;
        al_destroy_event_queue(queue);
        return false;
    }

    // Register event sources
    al_register_event_source(queue, al_get_video_event_source(video));
    al_register_event_source(queue, al_get_display_event_source(display));

    // Start playing the video
    al_start_video(video, al_get_default_mixer());

    // Set the video to play on the display
    al_set_video_playing(video, true);

    bool done = false;
    ALLEGRO_EVENT event;
    ALLEGRO_BITMAP* frame = nullptr;

    while (!done) {
        // Wait for the next event
        al_wait_for_event(queue, &event);

        switch (event.type) {
        case ALLEGRO_EVENT_VIDEO_FRAME_SHOW:
            // Get the current video frame
            frame = al_get_video_frame(video);
            if (frame) {
                // Clear the display
                al_clear_to_color(al_map_rgb(0, 0, 0));

                // Calculate the position to center the video on the display
                int display_width = al_get_display_width(display);
                int display_height = al_get_display_height(display);
                int video_width = al_get_bitmap_width(frame);
                int video_height = al_get_bitmap_height(frame);

                float scale_x = (float)display_width / video_width;
                float scale_y = (float)display_height / video_height;
                float scale = (scale_x < scale_y) ? scale_x : scale_y;

                int dest_x = (display_width - video_width * scale) / 2;
                int dest_y = (display_height - video_height * scale) / 2;

                // Draw the frame on the display
                al_draw_scaled_bitmap(
                    frame,
                    0, 0, video_width, video_height,
                    dest_x, dest_y, video_width * scale, video_height * scale,
                    0
                );

                // Flip the display to show the frame
                al_flip_display();
            }
            break;

        case ALLEGRO_EVENT_VIDEO_FINISHED:
            // Video has finished playing
            done = true;
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            // Window close button was clicked
            done = true;
            break;
        }
    }

    // Clean up resources
    al_set_video_playing(video, false);
    al_close_video(video);
    al_destroy_event_queue(queue);

    return true;
}



















using namespace std;

double p2t(double x, double maxp, double maxt) {
	return double(x) / maxp * maxt;
}

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int screen1(room& r, fb bos) {

    const int cam_w = 1888;
    const int cam_h = 992;
    const double FPS = 60.0;
    int map_w = 16000;
    int map_h = 2880;
    int cam_x = 0;
    int cam_y = 2880 - 992;
    double cam_tx;
    double cam_ty;
    int walking_frame = 0;
    int fighting_frame = 0;
    int dying_frame = 0;
    int gaurding_frame = 0;


    if (!al_init()) {
        std::cerr << "al_init() failed\n";
        return -1;
    }

    // 2) Primitives addon (for drawing)
    if (!al_init_primitives_addon()) {
        std::cerr << "al_init_primitives_addon() failed\n";
        return -1;
    }
    al_install_audio();
    al_init_font_addon(); 
    al_init_ttf_addon();
    al_init_video_addon();
    al_init_acodec_addon();
    al_reserve_samples(4);
    
    

    if (!al_init_font_addon) {
        std::cerr << "font failure failed\n";
        return -1;
    }
    // 3) Enable resizable windows (must be before creating the display)
    al_set_new_display_flags(ALLEGRO_RESIZABLE);

    // 4) Create the display
    ALLEGRO_DISPLAY* disp = al_create_display(cam_w, cam_h);
    if (!disp) {
        std::cerr << "al_create_display() failed\n";
        return -1;
    }

    // 5) Create a 60 FPS timer
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        std::cerr << "al_create_timer() failed\n";
        al_destroy_display(disp);
        return -1;
    }

    ifstream file(r.csvfile);

    if (!file.is_open()) {
        cout << "Error file me h"; return 0;
    }
    vector<vector<int>> map;
    string line;

    while (getline(file, line)) {
        vector<int> row;
        stringstream ss(line);
        string cell;

        while (getline(ss, cell, ',')) {
            row.push_back(stoi(cell));
        }

        map.push_back(row);
    }

    vector<vector<int>> map1 = map;;


    file.close();

    ifstream file1("boss.csv");

    if (!file1.is_open()) {
        cout << "Error file me h"; return 0;
    }
    vector<vector<int>> bmap;
    string line1;

    while (getline(file1, line1)) {
        vector<int> row;
        stringstream ss(line1);
        string cell;

        while (getline(ss, cell, ',')) {
            row.push_back(stoi(cell));
        }

        bmap.push_back(row);
    }




    file1.close();

    if (!al_init_image_addon()) {
        cerr << "Failed to initialize al_init_image_addon!" << endl;
        return -1;
    }

    ALLEGRO_FONT* font1 = al_load_ttf_font("font1/fontiuse.ttf", 30, 0);

    ALLEGRO_FONT* font = al_load_font("Menu.ttf", 100, 0);
    ALLEGRO_FONT* developerFont = al_load_font("developer.ttf", 60, 0);
    ALLEGRO_FONT* arial = al_load_font("arial.ttf", 40, 0);
    ALLEGRO_BITMAP* button = al_load_bitmap("button.png");


    ALLEGRO_BITMAP* ismail = al_load_bitmap("ismail.png");
    ALLEGRO_BITMAP* mehdi = al_load_bitmap("mehdi.png");
    ALLEGRO_BITMAP* qadrain = al_load_bitmap("Qadrain.png");
    ALLEGRO_BITMAP* ismail2 = al_load_bitmap("ismail2.png");

    vector<ALLEGRO_BITMAP*> tiles;

    for (int i = 0; i < r.tiles.size(); i++) {
        tiles.push_back(al_load_bitmap(r.tiles[i].c_str()));
	}   

    for (int i = 0; i < 98; i++) {
        if (!tiles[i]) {
            cout << "Prob : " << i << endl;
        }
    }

	cout << "Choose from 1 to 4. (for, 1 knight, 2 mage, 3 archer, 4 rogue)" << endl;

    enum AnimationState {
        walking,
        fighting,
        dying,
        idle,
        gaurding
    };

    enum GameState { menu, playing, inventory, dp, instruction, help };
    GameState curstate = menu;

	int ch=1;// cin >> ch;
    if (ch == 1) {
		string loc[7] = { "walking_sprites.png", "walking_sprites.png", "attack_sprites.png", "death_sprites.png", "Shield.png", "Attack_2.png", "Attack_3.png"};
        r.p = new knight(r.px, r.py, 40, 40, 40, 2, 50, loc);
	}
	else if (ch == 2) {
		//r.p = new mage(r.px, r.py,  40, 40, 100, 10, 5, "greenstone.png");
	}
	else if (ch == 3) {
		//r.p = new archer(r.px, r.py, 40, 40, 100, 10, 5, "greenstone.png");
	}
	else if (ch == 4) {
		//r.p = new rogue(r.px, r.py, 40, 40, 100, 10, 5, "greenstone.png");
	}
	else {
		cout << "Invalid choice!" << endl;
		return -1;
	}

    player p = *r.p;
    ALLEGRO_BITMAP* walking_sprites = p.w_sprite;
    ALLEGRO_BITMAP* fighting_sprites = p.f_sprite;
    ALLEGRO_BITMAP* dying_sprites = p.d_sprite;
    ALLEGRO_BITMAP* idle_sprites = p.i_sprite;
    ALLEGRO_BITMAP* g_sprites = p.g_sprite;
    ALLEGRO_BITMAP* current_sprite = walking_sprites;
    AnimationState current_state = idle;

   /* ALLEGRO_BITMAP* player = (r.p)->sprite;*/

    double px = r.px;
    double py = r.py;
    int health = r.p->health;
    int att = r.p->attack;
    int pw = 70;
    int ph = 90;
    double pys = 0.0;
    double pxs = 0.0;
    double p_tx = double(px) / cam_w * 60;
    double p_ty = double(py) / cam_h * 32;

    
    al_install_keyboard();
    al_install_mouse();
    if (!al_install_mouse) {
        cout << "Mouse problem" << endl;
    }

    // 6) Event queue
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    if (!queue) {
        std::cerr << "al_create_event_queue() failed\n";
        al_destroy_timer(timer);
        al_destroy_display(disp);
        return -1;
    }


    // 7) Register display and timer events
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_keyboard_event_source());
    ALLEGRO_EVENT_SOURCE* mouse_source = al_get_mouse_event_source();
    if (!mouse_source) {
        cout << "Mouse event source is NULL!" << std::endl;
        exit(1);
    }
    al_register_event_source(queue, mouse_source);


    // 8) Start the timer
    al_start_timer(timer);

    double playerspeed = 7;

    bool running = true;
    bool redraw = true;
    bool falling = true;
    bool jump = false;
    double velocity = 0.0;
    double gravity = 1.0;
    double scale = 1.0; // Initial scale factor

    int new_width;
    int new_height;
    int ch1 = 0, ch2 = 0, ch3 = 0, ch4 = 0;

    int fx = 0;
    bool death = false;
    bool fight = false;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e1 = 0;
    int f = 0;
    int g = 0;
    int h = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int x = 0;
    bool a2 = false;
    bool moving_right = false;
    bool flip_face = false;
    int total_frame = al_get_bitmap_width(current_sprite) / 128;
    bool dash = false;
    int tframe = 0;
    bool gaurd = false;
    bool lvlup = false;
    bool keys[ALLEGRO_KEY_MAX] = { false };
    bool finalboss = false;
    int bframe = 0;
    bool brun = false;
    bool bshot = false;
    double run1 = 1;
    bool arrow = false;
    bool skill1 = false;
    bool dmg1 = false;
    bool skill2 = false;
    int s2 = 0;
    bool skill3 = false;
    int s3 = 0;
    bool restart = false;


    bool y = true;
    cam_tx = cam_x / map_w * map[0].size();
    cam_ty = cam_y / map_h * map.size();

    ALLEGRO_SAMPLE* bgm = al_load_sample("sound.ogg");
    ALLEGRO_SAMPLE* dt = al_load_sample("dead.mp3");

    ALLEGRO_SAMPLE_ID music;
    if (!bgm) {
        cout << "This " << endl;
        return 1;
    }


    int selected_option = 0, total_options = 5;

    ALLEGRO_VIDEO* vid = al_open_video("story.ogv");
    if (!vid) {
        cout << "Stuff gone wrong";
    }
    Story("st.ogv", disp);
    al_play_sample(bgm, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &music);



    while (running) {

        if (restart) {
            current_state = idle;
            current_sprite = walking_sprites;
            map = map1;
            r.p->health = 40;
            r.p->attack = 2;
            r.p->lvl = 1;
            r.p->exp = 0;
            health = r.p->health;
            att = r.p->attack;
            px = cam_w / 2;
            py = cam_h / 2 - 200;
            cam_x = 0;
            cam_y = map_h - cam_h;
            s1a = false; s2a = false; s3a = false;
            for (auto& t : r.treasures) {
                t->taken = false;
            }
            for (auto& e : r.enemies) {
                e->alive = true;
                e->death = false;
                e->health = e->h1;
                e->x = e->ix;
                e->y = e->iy;
                e->att = false;
                e->aggro = false;
                e->current_sprite = e->w_sprite;
            }
            finalboss = false;
            bos.x = bos.ix;
            bos.y = bos.iy;
            bos.health = bos.h1;
            restart = false;

        }


        if (finalboss == true && h == 0) {
            h++;
            finalboss = false;

            cam_y = 0;
            cam_x = 0;
            map_h = cam_h;
            map_w = cam_w;

            map = bmap;
            px = 300; py = 500;
			for (auto& e : r.enemies) {
                e->alive = false;
			}
        }

        ALLEGRO_EVENT ev;
        ALLEGRO_MOUSE_EVENT mouse;
        al_wait_for_event(queue, &ev);
        fx = 0;

        switch (ev.type) {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            running = false;
            break;

        case ALLEGRO_EVENT_DISPLAY_RESIZE:
            new_width = ev.display.width;
            new_height = ev.display.height;
            scale = std::min((double)new_width / cam_w, (double)new_height / cam_h);
            al_acknowledge_resize(disp);
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            mouse.button = ev.mouse.button;
            mouse.x = ev.mouse.x;
            mouse.y = ev.mouse.y;

            if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                if ((mouse.x > cam_w - 100 && mouse.x < cam_w && mouse.y > cam_h - 100 && mouse.y < cam_h) &&
                    curstate == playing) {
                    curstate = inventory;
                    redraw = true;
                }
                else if ((mouse.x > cam_w - 100 && mouse.x < cam_w && mouse.y > cam_h - 100 && mouse.y < cam_h) &&
                    curstate == inventory) {
                    curstate = playing;
                }
            }
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                curstate = menu;
                redraw = true;
            }

        
        }

        if (curstate == playing) {
            switch (ev.type) {

            case ALLEGRO_EVENT_KEY_DOWN:
                keys[ev.keyboard.keycode] = true;
                if (ev.keyboard.keycode == ALLEGRO_KEY_W && !falling && !skill2 && current_state !=dying) {
                    jump = true;
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_J && !fight && current_state != dying) {
                    fight = 1;
                    f++;
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_U && falling &&  s1a && current_state != dying) {
                    skill1 = true;
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_I && s2a && current_state != dying) {
                    skill2 = true;
                    s2 = 0;
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_O && s3a && current_state != dying) {
                    skill3 = true;
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_M) {
                    if (curstate == playing){
                        curstate = inventory;
                    redraw = true;
                }
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_L && !skill2 && !gaurd && current_state != dying && !dash) {
                    if (!flip_face && p_tx + 6 < map[0].size()) {
                        if ((map[p_ty][p_tx + 5] == -1) && (map[p_ty][p_tx + 6] == -1) && (map[p_ty + 1][p_tx + 5] == -1) && (map[p_ty + 1][p_tx + 5] == -1)
                            && (map[p_ty + 2][p_tx + 5] == -1) && (map[p_ty + 2][p_tx + 5] == -1) && (map[p_ty + 1][p_tx + 6] == -1) && (map[p_ty + 1][p_tx + 6] == -1)
                            && (map[p_ty + 2][p_tx + 6] == -1) && (map[p_ty + 2][p_tx + 6] == -1)) {

                            dash = true;

                        }
                    }
                    else if (flip_face && p_tx - 6 > 0) {
                        if ((map[p_ty][p_tx - 5] == -1) && (map[p_ty][p_tx - 6] == -1) && (map[p_ty + 1][p_tx - 5] == -1) && (map[p_ty + 1][p_tx - 5] == -1)
                            && (map[p_ty + 2][p_tx - 5] == -1) && (map[p_ty + 2][p_tx - 5] == -1) && (map[p_ty + 1][p_tx - 6] == -1) && (map[p_ty + 1][p_tx - 6] == -1)
                            && (map[p_ty + 2][p_tx - 6] == -1) && (map[p_ty + 2][p_tx - 6] == -1)) {


                            dash = true;

                        }
                    }
                }



                break;




            case ALLEGRO_EVENT_KEY_UP:


                keys[ev.keyboard.keycode] = false;
                if (ev.keyboard.keycode == ALLEGRO_KEY_K) {
                    gaurd = false;
                }
                break;

            case ALLEGRO_EVENT_TIMER:
                // Movement logic here
                if (a % 6 == 0) {
                    if (current_state == walking) {
                        walking_frame = (walking_frame + 1) % total_frame;
                        redraw = true;
                    }
                    else if (current_state == dying) {
                        dying_frame = (dying_frame + 1) % total_frame;
                        redraw = true;
                    }
                }


                if (n % 8 == 0) {
                    m = (m + 1) % 8;
                } n++;

                p_tx = double(px + cam_x) / double(map_w) * map[0].size();
                p_ty = double(py + cam_y) / double(map_h) * map.size();
                cam_tx = double(cam_x) / double(map_w) * map[0].size();
                cam_ty = double(cam_y) / double(map_h) * map.size();
                pys = p_ty - int(p_ty);
                pxs = p_tx - int(p_tx);
                double mx = 1;


                if (keys[ALLEGRO_KEY_A] && !gaurd && !skill1 && !skill2 && current_state != dying) {

                    current_state = walking;
                    current_sprite = walking_sprites;
                    moving_right = true;
                    flip_face = true;

                    if (px > cam_w / 2) {
                        px -= playerspeed;
                        ch1 = 1;
                    }
                    else {
                        cam_x -= playerspeed;
                        ch1 = 2;
                    }
                    if (cam_x < 0) {
                        cam_x = 0;
                        px -= playerspeed;
                        ch1 = 1;
                        if (px < 0) {
                            px = 0;
                        }
                    }
                    if (falling) {
                        if (p_tx - 1 > 0 && (map[p_ty][p_tx - 1] != -1 || map[p_ty + 1][p_tx - 1] != -1) || map[p_ty + 2][p_tx - 1] != -1 || map[p_ty + 3][p_tx - 1] != -1) {
                            if (pxs * 32 < playerspeed) {
                                if (ch1 == 1) {
                                    px += playerspeed + 1 - pxs * 32;
                                }
                                else {
                                    cam_x += playerspeed + 1 - pxs * 32;
                                }
                            }
                        }
                    }
                    else if (p_tx - 1 > 0 && (map[p_ty][p_tx - 1] != -1 || map[p_ty + 1][p_tx - 1] != -1 || map[p_ty + 2][p_tx - 1] != -1)) {
                        if (pxs * 32 < playerspeed) {
                            if (ch1 == 1) {
                                px += playerspeed + 1 - pxs * 32;
                            }
                            else {
                                cam_x += playerspeed + 1 - pxs * 32;
                            }
                        }
                    }
                    redraw = true;


                }
                else if (current_state !=dying){
                    current_state = idle;
                    current_sprite = idle_sprites;
                } 
                if (keys[ALLEGRO_KEY_D] && !gaurd && !skill1 && !skill2 && current_state != dying) {

                    current_state = walking;
                    moving_right = true;
                    flip_face = false;

                    if (px < cam_w / 2) {
                        px += playerspeed; ch2 = 1;
                    }
                    else {
                        cam_x += playerspeed; ch2 = 2;
                    }
                    if (cam_x > map_w - cam_w) {
                        cam_x = map_w - cam_w;
                        px += playerspeed; ch2 = 1;
                        if (px + pw > cam_w) {
                            px = cam_w - pw;
                        } ch2 = 1;
                    }
                    if (falling) {
                        if (p_tx + 2 < map[0].size() && (map[p_ty + 1][p_tx + 2] != -1 || map[p_ty + 2][p_tx + 2] != -1) || map[p_ty + 3][p_tx + 2] != -1 || map[p_ty + 4][p_tx + 2] != -1) {
                            if (pxs * 32 > playerspeed) {
                                if (ch2 == 1) {
                                    px -= ((pxs * 32) - playerspeed + 1) - 16;
                                }
                                else {
                                    cam_x -= ((pxs * 32) - playerspeed + 1) - 16;
                                }
                            }
                        }
                    }
                    else if (p_tx + 2 < map[0].size() && (map[p_ty][p_tx + 2] != -1 || map[p_ty + 1][p_tx + 2] != -1 || map[p_ty + 2][p_tx + 2] != -1)) {
                        if (pxs * 32 > playerspeed) {
                            if (ch2 == 1) {
                                px -= ((pxs * 32) - playerspeed + 1) - 16;
                            }
                            else {
                                cam_x -= ((pxs * 32) - playerspeed + 1) - 16;
                            }
                        }
                    }

                    redraw = true;

                } 
                if (skill3) {
                    fight = true;
                    gaurd = true;
                    s3++;
                    if (s3 % 150 == 0) {
                        skill3 = false;
                        gaurd = false;
                        fight = false;
                    }
                }

                if (fight) {
                    current_state = fighting;
                    current_sprite = fighting_sprites;

                    if (a % 6 == 0) {
                        fighting_frame++;
                        if (fighting_frame % 2 == 0 && finalboss && bos.flip != flip_face && distance(px + pw / 2, py, bos.x + bos.w / 2, py) <= r.p->range) {
                            bos.health -= att; 
                        }
                    }

                    if (fighting_frame >= total_frame - 4) {
                        fighting_frame = 0;
                        fight = false;
                        current_state = idle;
                        current_sprite = idle_sprites;
                    }
                    redraw = true;
                }


                if (keys[ALLEGRO_KEY_K] && !skill2 && current_state != dying) {
                    gaurd = true;
                    gaurding_frame = (gaurding_frame + 1) % 2;
                    current_state = gaurding;
                    current_sprite = g_sprites;
                    redraw = true;

                }
                if (!finalboss) {
                    for (auto& t : r.treasures) {
                        if (!t->taken) {
                            if (distance(cam_x + px + pw / 2, py + cam_y + ph / 2, t->x + t->w / 2, t->y + t->h / 2) < 70) {
                                t->taken = true;
                                showskil(arial);
                                if (t->x == 12800) {
                                    s1a = true;
                                }
                                else if (t->x == 12960) {
                                    s2a = true;
                                }
                                else if (t->x == 3616) {
                                    s3a = true;
                                }
                            }              
                        }                  
                    }
                    for (auto& e : r.enemies) {
                        if (e->alive) {
                            if (e->x < cam_x + cam_w && e->x > cam_x && e->y > cam_y && e->y < cam_y + cam_h) {
                                if (fight && distance(cam_x + px + pw / 2, cam_y + py + ph / 2, e->x + 64, e->y + 64) < r.p->range) {
                                    if (a % 10 == 0) {
                                        e->health -= att;
                                    }
                                }
                                if (skill2 && distance(cam_x + px + pw / 2, py, e->x + 64, py) < 350) {
                                    if (l % 45 == 1) {
                                        e->health -= att;
                                    }
                                    if (e->flip) {
                                        e->x += s2 * 6;
                                    }
                                    else {
                                        e->x -= s2 * 6;
                                    }
                                }
                                if (dmg1 && distance(cam_x + px + pw / 2, py, e->x + 64, py) < r.p->range * 3) {
                                    e->health -= att * 2;
                                }
                                if (e->health < 0 && !e->death && e->alive) {
                                    e->death = true;
                                    e->f = 0;
                                    r.p->exp += pow(2, e->lvl);
                                    if (r.p->exp >= pow(2, r.p->lvl + 1)) {
                                        r.p->lvl++;
                                        showlvl(developerFont, r.p->lvl);
                                        redraw = true;
                                        r.p->exp -= pow(2, e->lvl);
                                        r.p->health += r.p->lvl >= 6 ? 16 * r.p->lvl : 16;
                                        r.p->attack += r.p->lvl >= 6 ? 6 : 3;
                                        health = r.p->health;
                                        att = r.p->attack;
                                        lvlup = true;
                                    }
                                }
                                if (distance(cam_x + px + pw / 2, cam_y + py + ph / 2, e->x + 64, e->y + 64) < e->range && !e->wback) {

                                    e->att = true;
                                    e->aggro = false;
                                }
                                else if (distance(cam_x + px + pw / 2, cam_y + py + ph / 2, e->x + 64, e->y + 64) < 250 && !e->wback) {



                                    e->aggro = true;
                                    e->att = false;
                                }
                                if (distance(e->x, e->y, e->ix + 64, e->iy + 64) > 250) {
                                    e->wback = true;
                                    e->aggro = false;
                                    e->att = false;
                                }

                            }
                        }
                    }
                    for (auto& e : r.enemies) {
                        if (e->alive) {



                            tframe = al_get_bitmap_width(e->current_sprite) / 128;

                            if (e->x < cam_x + cam_w && e->x > cam_x && e->y > cam_y && e->y < cam_y + cam_h) {

                                e->flip = px + cam_x + pw / 2 < e->x + 64 ? true : false;
                                
                                if (e->death) {}
                                
                                else if (e->aggro) {
                                    if (c % 6 == 0) {
                                        e->f = (e->f + 1) % tframe;
                                    }
                                    if (e->flip) {
                                        if (map[int(e->y / 32) + 3][int(e->x / 32) - 1] == -1) {
                                            e->x -= 3;
                                        }

                                    }

                                    else {
                                        if (map[int(e->y / 32) + 3][int(e->x / 32) + 2] == -1) {
                                            e->x += 3;
                                        }

                                    }
                                }


                                else if (e->att) {
                                    e->current_sprite = e->a_sprite;


                                    if (c % 10 == 0) {
                                        if (e->f == 2 && !gaurd && !skill1 && !dmg1) {
                                            health -= e->attack;

                                        }
                                        e->f = (e->f + 1) % tframe;
                                    }
                                }
                                else if (!e->aggro) {
                                    if (e->x < e->ix) {
                                        e->flip = false;
                                        e->current_sprite = e->w_sprite;
                                        tframe = al_get_bitmap_width(e->current_sprite) / 128;
                                        e->x += 3;

                                        if (c % 6 == 0) {
                                            e->f = (e->f + 1) % tframe;
                                        }
                                    }
                                    else if (e->x > e->ix) {
                                        e->flip = true;
                                        e->current_sprite = e->w_sprite;
                                        tframe = al_get_bitmap_width(e->current_sprite) / 128;
                                        e->x -= 3;
                                        if (c % 6 == 0) {
                                            e->f = (e->f + 1) % tframe;
                                        }
                                    }
                                    else if (e->x <= 5 + e->ix && e->x >= e->ix - 5) {
                                        e->wback = false; e->f = 0;
                                    }
                                }
                                
                            }
                        }
                    }
                    c++;
                }
                // final boss code

                else {
                    if (bos.alive) {


                        bos.flip = px + pw / 2 < bos.x + bos.w / 2 ? true : false;

                        if (distance(px + 64, py + py / 2, bos.x + 128, py + py / 2) > bos.range2 - 200 && !brun && !bshot && !skill2) {
                            bshot = true;
                        }
                        if (skill2 && distance(cam_x + px + pw / 2, py, bos.x + 128, py) < 350) {
                            if (s2 % 45 == 1) {
                                bos.health -= att;
                            }
                            if (bos.flip) {
                                bos.x += s2 * 6;
                            }
                            else {
                                bos.x -= s2 * 6;
                            }
                        }
                        if (bos.death) {
                            bos.current_sprite = bos.d_sprite;
                            bframe = al_get_bitmap_width(bos.current_sprite) / 128;
                            k++;
                            if (bos.f == bframe - 1) {
                                bos.death = false;
                                bos.alive = false;
                            }
                            if (k % 20 == 0)  bos.f = (bos.f + 1) % bframe;
                        }
                        else if (bshot) {
                            bos.current_sprite = bos.shot;
                            bframe = al_get_bitmap_width(bos.current_sprite) / 128;
                            if (k % 6 == 0)  bos.f = (bos.f + 1) % bframe;
                            k++;
                            if (bos.f == bframe - 1) {
                                bshot = false;
                                brun = true;
                                arrow = true;
                                y = bos.flip;
                            }
                        }

                        else if (!skill2 && distance(px + 64, py + py / 2, bos.x + 128, py + py / 2) >= bos.range) {
                            bos.current_sprite = bos.w_sprite;
                            if (brun) {
                                bos.current_sprite = bos.r_sprite;
                                run1 = 3;
                            }
                            bframe = al_get_bitmap_width(bos.current_sprite) / 128;

                            if (k % (10 - int(run1)) == 0)  bos.f = (bos.f + 1) % bframe;

                            if (bos.flip) {
                                bos.x -= 3 * run1;
                            }
                            else {
                                bos.x += 3 * run1;
                            }
                            k++;
                        }
                        else if (!skill2 && distance(px + 64, py + py / 2, bos.x + 128, py + py / 2) < bos.range) {
                            brun = false;
                            run1 = 1;

                            if (!a2) {
                                bos.current_sprite = bos.a_sprite;
                            }
                            else {
                                bos.current_sprite = bos.a2_sprite;
                            }
                            bframe = al_get_bitmap_width(bos.current_sprite) / 128;
                            if (k % 6 == 0) {
                                bos.f = (bos.f + 1) % bframe;
                                if (bos.f == 2 && !gaurd && !skill1 && !dmg1) {
                                    health -= bos.attack;
                                }
                            }
                            if (k % 30 == 0) {
                                a2 = !a2;
                                l++;
                            }

                            k++;

                        }
                        if (dmg1 && distance(cam_x + px + pw / 2, py, bos.x + 128, py) < r.p->range * 3) {

                            bos.health -= att * 2;
                        }
                        if (bos.health <= 0 && !bos.death && bos.alive) {
                            bos.death = true;
                            bos.f = 0;
                        }
                    }

                }

                if (arrow) {
                    if (py + ph/2 < bos.y + 224 && py+ph/2 > bos.y + 160 && ((px+pw < x+64 && px+pw > x) || (x + 64 > px && x+64<px+pw)) && !gaurd) {
                        health -= 20;
                    }
                }
                if (skill2) {
                    s2++;
                    if (s2 % 45 == 0) {
                        skill2 = false;
                    }
                }







                /*if (keys[ALLEGRO_KEY_S]) {
                    current_sprite = dying_sprites;
                    current_state = dying;
                    moving_right = false;

                }*/


                if (to_string(map[p_ty + 3][p_tx])[0] == '7' || to_string(map[p_ty + 3][p_tx + 1])[0] == '7') {
                    jump = true;
                    mx = 3;
                }

                if (map[p_ty + 2][p_tx] == -1 && map[p_ty + 2][p_tx + 1] == -1 || ((int(py + cam_y) + ph) % 32 < 28) && ((int(py + cam_y) + ph) % 32 > 3)) {
                    falling = true;
                }
                if (dash) {
                    fight = true;
                    current_state = walking;
                    current_sprite = walking_sprites;
                    if (!flip_face && p_tx + 4 < map[0].size()) {

                        if (px < cam_w / 2 || cam_x+cam_w + 32 > map[0].size() * 32) {
                            px += 32;
                        }
                        else {
                            cam_x += 32;
                        }
                    }
                    else if (flip_face && p_tx - 4 > 0) {

                        if (px > cam_w / 2 || cam_x - 32 < 0) {
                            px -= 32;
                        }
                        else {
                            cam_x -= 32;
                        }
                    }
                    b++;
                    if (b >= 5) {
                        dash = false;
                        b = 0;
                    }
                    redraw = true;
                }
                if (jump) {
                    velocity = -22 * mx;
                    falling = true;
                    jump = false;
                }
                dmg1 = false;

                if (falling) {
                    redraw = true;
                    if (skill1) {
                        if (velocity < 0) {
                            velocity = 0;
                        }
                    }
                    if (velocity < 23) {
                        velocity += gravity;
                    }

                    if (velocity < 0) {
                        if (py > cam_h / 2) {
                            py += velocity; ch3 = 1;
                        }
                        else {
                            cam_y += velocity; ch3 = 2;
                        }
                        if (cam_y < 0) {
                            py += cam_y;
                            cam_y = 0;
                            if (py < 0) {
                                py = 0;
                            } ch3 = 1;
                        }
                        if (p_ty - 1 > 0 && (map[p_ty - 1][p_tx] != -1 || map[p_ty - 1][p_tx + 1] != -1)) {
                            if (pys * 32 < velocity) {
                                if (ch3 == 1) {
                                    py += velocity + 1 - pys * 32;
                                }
                                else {
                                    cam_y += velocity + 1 - pys * 32;
                                }
                            }
                        }
                    }
                    else {
                        if (py < cam_h / 2) {
                            py += velocity; ch4 = 1;
                        }
                        else {
                            cam_y += velocity; ch4 = 2;
                        }
                        if (cam_y > map_h - cam_h) {
                            py += cam_y - map_h + cam_h;
                            cam_y = map_h - cam_h;
                            if (py + ph > cam_h) {
                                py = cam_h - ph;
                            } ch4 = 1;

                        }
                        if (int(py + cam_y - velocity) % 32 < 32 - ph % 32) {
                            if (p_ty + 3 < map.size() && (map[p_ty + 3][p_tx + 1] != -1 || map[p_ty + 3][p_tx] != -1)) {
                                if ((int(py + cam_y) + ph) % 32 < velocity) {
                                    if (ch4 == 1) {
                                        py -= (int(py + cam_y) + ph) % 32 + 1;
                                    }
                                    else {
                                        cam_y -= (int(py + cam_y) + ph) % 32 + 1;
                                    }
                                    falling = false; velocity = 0.0; mx = 1; dmg1 = skill1? true : false;skill1 = false;
                                }

                            }
                        }
                        else if (int(py + cam_y - velocity) % 32 >= 32 - ph % 32) {
                            if ((map[p_ty + 4][p_tx] != -1 || map[p_ty + 4][p_tx + 1] != -1) || (map[p_ty + 3][p_tx + 1] != -1 || map[p_ty + 3][p_tx] != -1)) {

                                if ((int(py + cam_y) + ph) % 32 < velocity) {

                                    if (ch4 == 1) {
                                        py -= (int(py + cam_y) + ph) % 32 + 1;
                                    }
                                    else {
                                        cam_y -= (int(py + cam_y) + ph) % 32 + 1;
                                    }
                                    falling = false; velocity = 0.0; mx = 1; skill1 = false; dmg1 = true;

                                }
                            }
                        }
                    }
                    redraw = true;
                }


                break;

            }
            if (health <= 0 && current_state != dying) {
                current_state = dying;

                curstate = menu;

                al_stop_sample(&music);

                al_play_sample(dt, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                gameover(arial);

            }



            a++;
            if (!r.enemies.back()->alive) {
                finalboss = true;
            }
        }


        else if (curstate == menu) {
            if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
                    selected_option = (selected_option + 1) % total_options;
                }
                else if (ev.keyboard.keycode == ALLEGRO_KEY_UP) {
                    selected_option = (selected_option - 1 + total_options) % total_options;
                }

                else if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                    if (selected_option == 0) {
                        if (health <= 0) {
                            restart = true;
                        }
                        curstate = playing;
                    }
                    if (selected_option == 1)  curstate = instruction;
                    if (selected_option == 2) curstate = help;
                    if (selected_option == 3) curstate = dp;
                    if (selected_option == 4) running = false;
                }
            }

        }
        else if (curstate == inventory) {
            if (ev.type == ALLEGRO_EVENT_KEY_DOWN && curstate != playing) {
                if (ev.keyboard.keycode == ALLEGRO_KEY_M) {
                    curstate = playing;
                }
            }

        }
        if (redraw && al_is_event_queue_empty(queue)) {


            if (curstate == menu) {
                draw_menu(selected_option, font, font, cam_w, cam_h, al_get_time());
            }
            else if (curstate == inventory) {
                showInventory(arial);
            }
            else if (curstate == dp) {
                showDevelopers(developerFont, mehdi, ismail, qadrain, ismail2);

            }
            else if (curstate == help) {
                showHelp(arial);
            }
            else if (curstate == instruction) {
                showInstruction(arial);
            }

            else {
                redraw = false;


                // Clear to black
                al_clear_to_color(al_map_rgb(240, 255, 255));

                // Scale the position and size of the rectangle
                // Original rectangle size: 100x100 (at position 100, 100)

             //ysdd


                double xs = cam_tx - int(cam_tx);
                double ys = cam_ty - int(cam_ty);





                for (int i = 0; i < 60; i++) {
                    for (int j = 0; j < 32; j++) {
                        if (cam_ty + j < map.size() && cam_tx + i < map[0].size() && map[cam_ty + j][cam_tx + i] >= 0) {
                            al_draw_bitmap(tiles[map[cam_ty + j][cam_tx + i]], (i * 32) - xs * 32, (j * 32) - ys * 32, 0);
                        }
                    }
                }
                for (int i = 0; i < (double(health) / double(r.p->health)) * 7; i++) {
                    al_draw_filled_rectangle(140 + i * 30, 70, 140 + 80 + i * 30, 105, al_map_rgb(255, 0, 0));
                }
                al_draw_rounded_rectangle(140 - 2, 70, 140 + (6 * 30) + 80 + 2, 105, 15, 15, al_map_rgb(129, 84, 56), 8);

                al_draw_circle(119, 88, 18, al_map_rgb(129, 84, 56), 7);

                al_draw_text(font1, al_map_rgb(0, 0, 0), 110, 70, 0, to_string(r.p->lvl).c_str());

                if (!finalboss) {

                    for (auto& t : r.treasures) {
                        if (!t->taken) {

                            if (t->x< cam_x + cam_w && t->x + t->w > cam_x && t->y + t->h > cam_y && t->y < cam_y + cam_h) {
                                
                                al_draw_scaled_bitmap(t->sprite, 41.55 * m, 0, 41.55, 40, t->x-cam_x, t->y-cam_y, 41.55, 40, 0);
                            }

                        }
                    }

                    for (auto& e : r.enemies) {
                        if (e->alive) {
                            if (e->x< cam_x + cam_w && e->x + e->w > cam_x && e->y + e->h > cam_y && e->y < cam_y + cam_h) {

                                if (e->death) {
                                    e->current_sprite = e->d_sprite;
                                    tframe = al_get_bitmap_width(e->current_sprite) / 128;
                                    if (e1 % 20 == 0) {
                                        e->f++ % tframe;
                                    }
                                    e1++;
                                    if (e->f == tframe - 1) {
                                        e->alive = false;
                                        e->death = false;
                                    }
                                }

                                e->draw(cam_x, cam_y, velocity);

                            }
                        }
                    }
                }
                else {
                    if (bos.death) {
                        bos.current_sprite = bos.d_sprite;
                    }
                    bframe = al_get_bitmap_width(bos.current_sprite) / 128;
                    for (int i = 0; i < (double(bos.health) / double(bos.h1)) * 40; i++) {
                        al_draw_filled_rectangle(300 + i * 30, 800, 300 + 80 + i * 30, 835, al_map_rgb(129, 0, 0));
                    }
                    al_draw_rounded_rectangle(300 - 2, 800, 300 + (20 * 30) + 653 + 2, 835, 15, 15, al_map_rgb(0, 0, 0), 8);
                    bos.f = bos.f % bframe;
                    al_draw_scaled_bitmap(bos.current_sprite, bos.f * 128, 0, 128, 128, bos.x, bos.y, 256, 256, bos.flip);
                }

                // Draw a scaled red rectangle

                if (current_state == walking) {
                    fx = walking_frame * 128;
                }
                else if (current_state == fighting) {

                    tframe = al_get_bitmap_width(current_sprite);

                    fighting_frame = fighting_frame % tframe;

                    fx = fighting_frame * 128;
                    if (f % 3 == 1) {
                        current_sprite = r.p->f_sprite;
                    }
                    else if (f % 3 == 2) {
                        current_sprite = r.p->f2_sprite;
                    }
                    else if (f % 3 == 0) {
                        current_sprite = r.p->f3_sprite;
                    }
                }
                else if (current_state == idle) {
                    fx = 0;
                }
                else if (current_state == gaurding) {
                    fx = 1;
                }
                else if (current_state == dying) {
                    current_sprite = r.p->d_sprite;
                    tframe = al_get_bitmap_width(current_sprite);
                    if (fx != tframe - 1)
                        fx = (fx + 1) % tframe;
                }
                if (skill1 || skill2) {
                    current_sprite = r.p->d_sprite;
                    tframe = al_get_bitmap_width(current_sprite);
                    fx = 1;
                }
                if (skill3) {
                    tframe = al_get_bitmap_width(current_sprite);

                    fighting_frame = fighting_frame % tframe;

                    fx = fighting_frame * 128;
                    if (f % 3 == 1) {
                        current_sprite = r.p->f_sprite;
                    }
                    else if (f % 3 == 2) {
                        current_sprite = r.p->f2_sprite;
                    }
                    else if (f % 3 == 0) {
                        current_sprite = r.p->f3_sprite;
                    }
                }


                al_draw_scaled_bitmap(current_sprite, fx, 0, 128, 90,
                    px - 37, py, 128, 90, flip_face);

                if (arrow) {

                    l++;
                    if (l % 60 == 0) {
                        arrow = false;
                        l = 0;
                    }
                    x = y ? bos.x - l * 12 : bos.x + 256 + l * 12;
                    al_draw_scaled_bitmap(bos.charge_sprite, 0, 0, 64, 64, x, bos.y + 128, 128, 128, y);
                }


                /*for (auto& e : r.enemies) {
                    if (e.x<cam_x + cam_w && e.x>cam_x && e.y > cam_y && e.y < cam_y + cam_h) {
                        al_draw_scaled_bitmap(e.w_sprite, 0, 0, 128, 128, e.x-cam_x, e.y-cam_y, 128, 128, 0);
                    }
                }*/


                al_draw_bitmap(button, cam_w - 100, cam_h - 100, 0);



                /*al_draw_bitmap(player, px, py, 0);*/

                al_flip_display();

            }
        }

    }
		

    // 10) Cleanup
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_display(disp);
    al_shutdown_primitives_addon();

    return 0;
}
