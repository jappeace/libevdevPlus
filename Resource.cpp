/*
    This file is part of libevdevPlus.
    Copyright (C) 2018-2021 Reimu NotMoe <reimu@sudomaker.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the MIT License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include "evdevPlus.hpp"

const std::unordered_map<std::string, int> evdevPlus::Table_ModifierKeys = {
	{"ALT", KEY_LEFTALT}, {"ALT_L", KEY_LEFTALT}, {"ALT_R", KEY_RIGHTALT},
	{"SHIFT", KEY_LEFTSHIFT}, {"SHIFT_L", KEY_LEFTSHIFT}, {"SHIFT_R", KEY_RIGHTSHIFT},
	{"CTRL", KEY_LEFTCTRL}, {"CTRL_L", KEY_LEFTCTRL}, {"CTRL_R", KEY_RIGHTCTRL},
	{"SUPER", KEY_LEFTMETA}, {"SUPER_L", KEY_LEFTMETA}, {"SUPER_R", KEY_RIGHTMETA},
	{"META", KEY_LEFTMETA}, {"META_L", KEY_LEFTMETA}, {"META_R", KEY_RIGHTMETA}
};

const std::unordered_map<std::string, int> evdevPlus::Table_FunctionKeys = {
	{"UP", KEY_UP}, {"DOWN", KEY_DOWN}, {"LEFT", KEY_LEFT}, {"RIGHT", KEY_RIGHT},
	{"TAB", KEY_TAB}, {"CAPSLOCK", KEY_CAPSLOCK}, {"NUMLOCK", KEY_NUMLOCK}, {"SCROLLLOCK", KEY_SCROLLLOCK}, {"ESC", KEY_ESC}, {"ENTER", KEY_ENTER}, {"BACKSPACE", KEY_BACKSPACE}, {"DELETE", KEY_DELETE},
	{"INSERT", KEY_INSERT}, {"HOME", KEY_HOME}, {"END", KEY_END}, {"PAGEUP", KEY_PAGEUP}, {"PAGEDOWN", KEY_PAGEDOWN}, {"SYSRQ", KEY_SYSRQ}, {"PAUSE", KEY_PAUSE},
	{"F1", KEY_F1}, {"F2", KEY_F2}, {"F3", KEY_F3}, {"F4", KEY_F4}, {"F5", KEY_F5}, {"F6", KEY_F6}, {"F7", KEY_F7}, {"F8", KEY_F8}, {"F9", KEY_F9}, {"F10", KEY_F10}, {"F11", KEY_F11}, {"F12", KEY_F12}
};

const std::unordered_map<char, int> evdevPlus::Table_LowerKeys = {
	{'\n', KEY_ENTER}, {'\t', KEY_TAB}, {' ', KEY_SPACE}, {'.', KEY_DOT}, {',', KEY_COMMA}, {'/', KEY_SLASH}, {'\\', KEY_BACKSLASH}, {';', KEY_SEMICOLON}, {'-', KEY_MINUS}, {'=', KEY_EQUAL}, {'`', KEY_GRAVE}, {'\'', KEY_APOSTROPHE}, {'[', KEY_LEFTBRACE}, {']', KEY_RIGHTBRACE},
	{'0', KEY_0}, {'1', KEY_1}, {'2', KEY_2}, {'3', KEY_3}, {'4', KEY_4}, {'5', KEY_5}, {'6', KEY_6}, {'7', KEY_7}, {'8', KEY_8}, {'9', KEY_9},
	{'a', KEY_A}, {'b', KEY_B}, {'c', KEY_C}, {'d', KEY_D}, {'e', KEY_E}, {'f', KEY_F}, {'g', KEY_G}, {'h', KEY_H}, {'i', KEY_I}, {'j', KEY_J}, {'k', KEY_K}, {'l', KEY_L}, {'m', KEY_M}, {'n', KEY_N}, {'o', KEY_O}, {'p', KEY_P}, {'q', KEY_Q}, {'r', KEY_R}, {'s', KEY_S}, {'t', KEY_T}, {'u', KEY_U}, {'v', KEY_V}, {'w', KEY_W}, {'x', KEY_X}, {'y', KEY_Y}, {'z', KEY_Z}
};

const std::unordered_map<char, int> evdevPlus::Table_UpperKeys = {
	{'>', KEY_DOT}, {'<', KEY_COMMA}, {'?', KEY_SLASH}, {'|', KEY_BACKSLASH}, {':', KEY_SEMICOLON}, {'_', KEY_MINUS}, {'+', KEY_EQUAL}, {'~', KEY_GRAVE}, {'"', KEY_APOSTROPHE}, {'{', KEY_LEFTBRACE}, {'}', KEY_RIGHTBRACE},
	{')', KEY_0}, {'!', KEY_1}, {'@', KEY_2}, {'#', KEY_3}, {'$', KEY_4}, {'%', KEY_5}, {'^', KEY_6}, {'&', KEY_7}, {'*', KEY_8}, {'(', KEY_9},
	{'A', KEY_A}, {'B', KEY_B}, {'C', KEY_C}, {'D', KEY_D}, {'E', KEY_E}, {'F', KEY_F}, {'G', KEY_G}, {'H', KEY_H}, {'I', KEY_I}, {'J', KEY_J}, {'K', KEY_K}, {'L', KEY_L}, {'M', KEY_M}, {'N', KEY_N}, {'O', KEY_O}, {'P', KEY_P}, {'Q', KEY_Q}, {'R', KEY_R}, {'S', KEY_S}, {'T', KEY_T}, {'U', KEY_U}, {'V', KEY_V}, {'W', KEY_W}, {'X', KEY_X}, {'Y', KEY_Y}, {'Z', KEY_Z}
};

const std::unordered_map<std::string, int> evdevPlus::Table_KeyCodes = {
	{"EV_KEY", EV_KEY}, {"EV_REL", EV_REL}, {"EV_ABS", EV_ABS},
	{"KEY_ESC", KEY_ESC}, {"KEY_1", KEY_1},
	{"KEY_2", KEY_2}, {"KEY_3", KEY_3}, {"KEY_4", KEY_4}, {"KEY_5", KEY_5}, {"KEY_6", KEY_6}, {"KEY_7", KEY_7},
	{"KEY_8", KEY_8}, {"KEY_9", KEY_9}, {"KEY_0", KEY_0}, {"KEY_MINUS", KEY_MINUS}, {"KEY_EQUAL", KEY_EQUAL},
	{"KEY_BACKSPACE", KEY_BACKSPACE}, {"KEY_TAB", KEY_TAB}, {"KEY_Q", KEY_Q}, {"KEY_W", KEY_W}, {"KEY_E", KEY_E},
	{"KEY_R", KEY_R}, {"KEY_T", KEY_T}, {"KEY_Y", KEY_Y}, {"KEY_U", KEY_U}, {"KEY_I", KEY_I}, {"KEY_O", KEY_O},
	{"KEY_P", KEY_P}, {"KEY_LEFTBRACE", KEY_LEFTBRACE}, {"KEY_RIGHTBRACE", KEY_RIGHTBRACE},
	{"KEY_ENTER", KEY_ENTER}, {"KEY_LEFTCTRL", KEY_LEFTCTRL}, {"KEY_A", KEY_A}, {"KEY_S", KEY_S}, {"KEY_D", KEY_D},
	{"KEY_F", KEY_F}, {"KEY_G", KEY_G}, {"KEY_H", KEY_H}, {"KEY_J", KEY_J}, {"KEY_K", KEY_K}, {"KEY_L", KEY_L},
	{"KEY_SEMICOLON", KEY_SEMICOLON}, {"KEY_APOSTROPHE", KEY_APOSTROPHE}, {"KEY_GRAVE", KEY_GRAVE},
	{"KEY_LEFTSHIFT", KEY_LEFTSHIFT}, {"KEY_BACKSLASH", KEY_BACKSLASH}, {"KEY_Z", KEY_Z}, {"KEY_X", KEY_X},
	{"KEY_C", KEY_C}, {"KEY_V", KEY_V}, {"KEY_B", KEY_B}, {"KEY_N", KEY_N}, {"KEY_M", KEY_M},
	{"KEY_COMMA", KEY_COMMA}, {"KEY_DOT", KEY_DOT}, {"KEY_SLASH", KEY_SLASH}, {"KEY_RIGHTSHIFT", KEY_RIGHTSHIFT},
	{"KEY_KPASTERISK", KEY_KPASTERISK}, {"KEY_LEFTALT", KEY_LEFTALT}, {"KEY_SPACE", KEY_SPACE},
	{"KEY_CAPSLOCK", KEY_CAPSLOCK}, {"KEY_F1", KEY_F1}, {"KEY_F2", KEY_F2}, {"KEY_F3", KEY_F3}, {"KEY_F4", KEY_F4},
	{"KEY_F5", KEY_F5}, {"KEY_F6", KEY_F6}, {"KEY_F7", KEY_F7}, {"KEY_F8", KEY_F8}, {"KEY_F9", KEY_F9},
	{"KEY_F10", KEY_F10}, {"KEY_NUMLOCK", KEY_NUMLOCK}, {"KEY_SCROLLLOCK", KEY_SCROLLLOCK}, {"KEY_KP7", KEY_KP7},
	{"KEY_KP8", KEY_KP8}, {"KEY_KP9", KEY_KP9}, {"KEY_KPMINUS", KEY_KPMINUS}, {"KEY_KP4", KEY_KP4},
	{"KEY_KP5", KEY_KP5}, {"KEY_KP6", KEY_KP6}, {"KEY_KPPLUS", KEY_KPPLUS}, {"KEY_KP1", KEY_KP1},
	{"KEY_KP2", KEY_KP2}, {"KEY_KP3", KEY_KP3}, {"KEY_KP0", KEY_KP0}, {"KEY_KPDOT", KEY_KPDOT},
	{"KEY_ZENKAKUHANKAKU", KEY_ZENKAKUHANKAKU}, {"KEY_102ND", KEY_102ND}, {"KEY_F11", KEY_F11},
	{"KEY_F12", KEY_F12}, {"KEY_RO", KEY_RO}, {"KEY_KATAKANA", KEY_KATAKANA}, {"KEY_HIRAGANA", KEY_HIRAGANA},
	{"KEY_HENKAN", KEY_HENKAN}, {"KEY_KATAKANAHIRAGANA", KEY_KATAKANAHIRAGANA}, {"KEY_MUHENKAN", KEY_MUHENKAN},
	{"KEY_KPJPCOMMA", KEY_KPJPCOMMA}, {"KEY_KPENTER", KEY_KPENTER}, {"KEY_RIGHTCTRL", KEY_RIGHTCTRL},
	{"KEY_KPSLASH", KEY_KPSLASH}, {"KEY_SYSRQ", KEY_SYSRQ}, {"KEY_RIGHTALT", KEY_RIGHTALT},
	{"KEY_LINEFEED", KEY_LINEFEED}, {"KEY_HOME", KEY_HOME}, {"KEY_UP", KEY_UP}, {"KEY_PAGEUP", KEY_PAGEUP},
	{"KEY_LEFT", KEY_LEFT}, {"KEY_RIGHT", KEY_RIGHT}, {"KEY_END", KEY_END}, {"KEY_DOWN", KEY_DOWN},
	{"KEY_PAGEDOWN", KEY_PAGEDOWN}, {"KEY_INSERT", KEY_INSERT}, {"KEY_DELETE", KEY_DELETE},
	{"KEY_MACRO", KEY_MACRO}, {"KEY_MUTE", KEY_MUTE}, {"KEY_VOLUMEDOWN", KEY_VOLUMEDOWN},
	{"KEY_VOLUMEUP", KEY_VOLUMEUP}, {"KEY_POWER", KEY_POWER}, {"KEY_KPEQUAL", KEY_KPEQUAL},
	{"KEY_KPPLUSMINUS", KEY_KPPLUSMINUS}, {"KEY_PAUSE", KEY_PAUSE}, {"KEY_SCALE", KEY_SCALE},
	{"KEY_KPCOMMA", KEY_KPCOMMA}, {"KEY_HANGEUL", KEY_HANGEUL}, {"KEY_HANGUEL", KEY_HANGUEL},
	{"KEY_HANJA", KEY_HANJA}, {"KEY_YEN", KEY_YEN}, {"KEY_LEFTMETA", KEY_LEFTMETA},
	{"KEY_RIGHTMETA", KEY_RIGHTMETA}, {"KEY_COMPOSE", KEY_COMPOSE}, {"KEY_STOP", KEY_STOP},
	{"KEY_AGAIN", KEY_AGAIN}, {"KEY_PROPS", KEY_PROPS}, {"KEY_UNDO", KEY_UNDO}, {"KEY_FRONT", KEY_FRONT},
	{"KEY_COPY", KEY_COPY}, {"KEY_OPEN", KEY_OPEN}, {"KEY_PASTE", KEY_PASTE}, {"KEY_FIND", KEY_FIND},
	{"KEY_CUT", KEY_CUT}, {"KEY_HELP", KEY_HELP}, {"KEY_MENU", KEY_MENU}, {"KEY_CALC", KEY_CALC},
	{"KEY_SETUP", KEY_SETUP}, {"KEY_SLEEP", KEY_SLEEP}, {"KEY_WAKEUP", KEY_WAKEUP}, {"KEY_FILE", KEY_FILE},
	{"KEY_SENDFILE", KEY_SENDFILE}, {"KEY_DELETEFILE", KEY_DELETEFILE}, {"KEY_XFER", KEY_XFER},
	{"KEY_PROG1", KEY_PROG1}, {"KEY_PROG2", KEY_PROG2}, {"KEY_WWW", KEY_WWW}, {"KEY_MSDOS", KEY_MSDOS},
	{"KEY_COFFEE", KEY_COFFEE}, {"KEY_SCREENLOCK", KEY_SCREENLOCK}, {"KEY_ROTATE_DISPLAY", KEY_ROTATE_DISPLAY},
	{"KEY_DIRECTION", KEY_DIRECTION}, {"KEY_CYCLEWINDOWS", KEY_CYCLEWINDOWS}, {"KEY_MAIL", KEY_MAIL},
	{"KEY_BOOKMARKS", KEY_BOOKMARKS}, {"KEY_COMPUTER", KEY_COMPUTER}, {"KEY_BACK", KEY_BACK},
	{"KEY_FORWARD", KEY_FORWARD}, {"KEY_CLOSECD", KEY_CLOSECD}, {"KEY_EJECTCD", KEY_EJECTCD},
	{"KEY_EJECTCLOSECD", KEY_EJECTCLOSECD}, {"KEY_NEXTSONG", KEY_NEXTSONG}, {"KEY_PLAYPAUSE", KEY_PLAYPAUSE},
	{"KEY_PREVIOUSSONG", KEY_PREVIOUSSONG}, {"KEY_STOPCD", KEY_STOPCD}, {"KEY_RECORD", KEY_RECORD},
	{"KEY_REWIND", KEY_REWIND}, {"KEY_PHONE", KEY_PHONE}, {"KEY_ISO", KEY_ISO}, {"KEY_CONFIG", KEY_CONFIG},
	{"KEY_HOMEPAGE", KEY_HOMEPAGE}, {"KEY_REFRESH", KEY_REFRESH}, {"KEY_EXIT", KEY_EXIT}, {"KEY_MOVE", KEY_MOVE},
	{"KEY_EDIT", KEY_EDIT}, {"KEY_SCROLLUP", KEY_SCROLLUP}, {"KEY_SCROLLDOWN", KEY_SCROLLDOWN},
	{"KEY_KPLEFTPAREN", KEY_KPLEFTPAREN}, {"KEY_KPRIGHTPAREN", KEY_KPRIGHTPAREN}, {"KEY_NEW", KEY_NEW},
	{"KEY_REDO", KEY_REDO}, {"KEY_F13", KEY_F13}, {"KEY_F14", KEY_F14}, {"KEY_F15", KEY_F15}, {"KEY_F16", KEY_F16},
	{"KEY_F17", KEY_F17}, {"KEY_F18", KEY_F18}, {"KEY_F19", KEY_F19}, {"KEY_F20", KEY_F20}, {"KEY_F21", KEY_F21},
	{"KEY_F22", KEY_F22}, {"KEY_F23", KEY_F23}, {"KEY_F24", KEY_F24}, {"KEY_PLAYCD", KEY_PLAYCD},
	{"KEY_PAUSECD", KEY_PAUSECD}, {"KEY_PROG3", KEY_PROG3}, {"KEY_PROG4", KEY_PROG4},
	{"KEY_DASHBOARD", KEY_DASHBOARD}, {"KEY_SUSPEND", KEY_SUSPEND}, {"KEY_CLOSE", KEY_CLOSE},
	{"KEY_PLAY", KEY_PLAY}, {"KEY_FASTFORWARD", KEY_FASTFORWARD}, {"KEY_BASSBOOST", KEY_BASSBOOST},
	{"KEY_PRINT", KEY_PRINT}, {"KEY_HP", KEY_HP}, {"KEY_CAMERA", KEY_CAMERA}, {"KEY_SOUND", KEY_SOUND},
	{"KEY_QUESTION", KEY_QUESTION}, {"KEY_EMAIL", KEY_EMAIL}, {"KEY_CHAT", KEY_CHAT}, {"KEY_SEARCH", KEY_SEARCH},
	{"KEY_CONNECT", KEY_CONNECT}, {"KEY_FINANCE", KEY_FINANCE}, {"KEY_SPORT", KEY_SPORT}, {"KEY_SHOP", KEY_SHOP},
	{"KEY_ALTERASE", KEY_ALTERASE}, {"KEY_CANCEL", KEY_CANCEL}, {"KEY_BRIGHTNESSDOWN", KEY_BRIGHTNESSDOWN},
	{"KEY_BRIGHTNESSUP", KEY_BRIGHTNESSUP}, {"KEY_MEDIA", KEY_MEDIA}, {"KEY_SWITCHVIDEOMODE", KEY_SWITCHVIDEOMODE},
	{"KEY_KBDILLUMTOGGLE", KEY_KBDILLUMTOGGLE}, {"KEY_KBDILLUMDOWN", KEY_KBDILLUMDOWN},
	{"KEY_KBDILLUMUP", KEY_KBDILLUMUP}, {"KEY_SEND", KEY_SEND}, {"KEY_REPLY", KEY_REPLY},
	{"KEY_FORWARDMAIL", KEY_FORWARDMAIL}, {"KEY_SAVE", KEY_SAVE}, {"KEY_DOCUMENTS", KEY_DOCUMENTS},
	{"KEY_BATTERY", KEY_BATTERY}, {"KEY_BLUETOOTH", KEY_BLUETOOTH}, {"KEY_WLAN", KEY_WLAN}, {"KEY_UWB", KEY_UWB},
	{"KEY_UNKNOWN", KEY_UNKNOWN}, {"KEY_VIDEO_NEXT", KEY_VIDEO_NEXT}, {"KEY_VIDEO_PREV", KEY_VIDEO_PREV},
	{"KEY_BRIGHTNESS_CYCLE", KEY_BRIGHTNESS_CYCLE}, {"KEY_BRIGHTNESS_AUTO", KEY_BRIGHTNESS_AUTO},
	{"KEY_BRIGHTNESS_ZERO", KEY_BRIGHTNESS_ZERO}, {"KEY_DISPLAY_OFF", KEY_DISPLAY_OFF}, {"KEY_WWAN", KEY_WWAN},
	{"KEY_WIMAX", KEY_WIMAX}, {"KEY_RFKILL", KEY_RFKILL}, {"KEY_MICMUTE", KEY_MICMUTE}, {"KEY_OK", KEY_OK},
	{"KEY_SELECT", KEY_SELECT}, {"KEY_GOTO", KEY_GOTO}, {"KEY_CLEAR", KEY_CLEAR}, {"KEY_POWER2", KEY_POWER2},
	{"KEY_OPTION", KEY_OPTION}, {"KEY_INFO", KEY_INFO}, {"KEY_TIME", KEY_TIME}, {"KEY_VENDOR", KEY_VENDOR},
	{"KEY_ARCHIVE", KEY_ARCHIVE}, {"KEY_PROGRAM", KEY_PROGRAM}, {"KEY_CHANNEL", KEY_CHANNEL},
	{"KEY_FAVORITES", KEY_FAVORITES}, {"KEY_EPG", KEY_EPG}, {"KEY_PVR", KEY_PVR}, {"KEY_MHP", KEY_MHP},
	{"KEY_LANGUAGE", KEY_LANGUAGE}, {"KEY_TITLE", KEY_TITLE}, {"KEY_SUBTITLE", KEY_SUBTITLE},
	{"KEY_ANGLE", KEY_ANGLE}, {"KEY_ZOOM", KEY_ZOOM}, {"KEY_MODE", KEY_MODE}, {"KEY_KEYBOARD", KEY_KEYBOARD},
	{"KEY_SCREEN", KEY_SCREEN}, {"KEY_PC", KEY_PC}, {"KEY_TV", KEY_TV}, {"KEY_TV2", KEY_TV2}, {"KEY_VCR", KEY_VCR},
	{"KEY_VCR2", KEY_VCR2}, {"KEY_SAT", KEY_SAT}, {"KEY_SAT2", KEY_SAT2}, {"KEY_CD", KEY_CD},
	{"KEY_TAPE", KEY_TAPE}, {"KEY_RADIO", KEY_RADIO}, {"KEY_TUNER", KEY_TUNER}, {"KEY_PLAYER", KEY_PLAYER},
	{"KEY_TEXT", KEY_TEXT}, {"KEY_DVD", KEY_DVD}, {"KEY_AUX", KEY_AUX}, {"KEY_MP3", KEY_MP3},
	{"KEY_AUDIO", KEY_AUDIO}, {"KEY_VIDEO", KEY_VIDEO}, {"KEY_DIRECTORY", KEY_DIRECTORY}, {"KEY_LIST", KEY_LIST},
	{"KEY_MEMO", KEY_MEMO}, {"KEY_CALENDAR", KEY_CALENDAR}, {"KEY_RED", KEY_RED}, {"KEY_GREEN", KEY_GREEN},
	{"KEY_YELLOW", KEY_YELLOW}, {"KEY_BLUE", KEY_BLUE}, {"KEY_CHANNELUP", KEY_CHANNELUP},
	{"KEY_CHANNELDOWN", KEY_CHANNELDOWN}, {"KEY_FIRST", KEY_FIRST}, {"KEY_LAST", KEY_LAST}, {"KEY_AB", KEY_AB},
	{"KEY_NEXT", KEY_NEXT}, {"KEY_RESTART", KEY_RESTART}, {"KEY_SLOW", KEY_SLOW}, {"KEY_SHUFFLE", KEY_SHUFFLE},
	{"KEY_BREAK", KEY_BREAK}, {"KEY_PREVIOUS", KEY_PREVIOUS}, {"KEY_DIGITS", KEY_DIGITS}, {"KEY_TEEN", KEY_TEEN},
	{"KEY_TWEN", KEY_TWEN}, {"KEY_VIDEOPHONE", KEY_VIDEOPHONE}, {"KEY_GAMES", KEY_GAMES},
	{"KEY_ZOOMIN", KEY_ZOOMIN}, {"KEY_ZOOMOUT", KEY_ZOOMOUT}, {"KEY_ZOOMRESET", KEY_ZOOMRESET},
	{"KEY_WORDPROCESSOR", KEY_WORDPROCESSOR}, {"KEY_EDITOR", KEY_EDITOR}, {"KEY_SPREADSHEET", KEY_SPREADSHEET},
	{"KEY_GRAPHICSEDITOR", KEY_GRAPHICSEDITOR}, {"KEY_PRESENTATION", KEY_PRESENTATION},
	{"KEY_DATABASE", KEY_DATABASE}, {"KEY_NEWS", KEY_NEWS}, {"KEY_VOICEMAIL", KEY_VOICEMAIL},
	{"KEY_ADDRESSBOOK", KEY_ADDRESSBOOK}, {"KEY_MESSENGER", KEY_MESSENGER},
	{"KEY_DISPLAYTOGGLE", KEY_DISPLAYTOGGLE}, {"KEY_BRIGHTNESS_TOGGLE", KEY_BRIGHTNESS_TOGGLE},
	{"KEY_SPELLCHECK", KEY_SPELLCHECK}, {"KEY_LOGOFF", KEY_LOGOFF}, {"KEY_DOLLAR", KEY_DOLLAR},
	{"KEY_EURO", KEY_EURO}, {"KEY_FRAMEBACK", KEY_FRAMEBACK}, {"KEY_FRAMEFORWARD", KEY_FRAMEFORWARD},
	{"KEY_CONTEXT_MENU", KEY_CONTEXT_MENU}, {"KEY_MEDIA_REPEAT", KEY_MEDIA_REPEAT},
	{"KEY_10CHANNELSUP", KEY_10CHANNELSUP}, {"KEY_10CHANNELSDOWN", KEY_10CHANNELSDOWN}, {"KEY_IMAGES", KEY_IMAGES},
	{"KEY_DEL_EOL", KEY_DEL_EOL}, {"KEY_DEL_EOS", KEY_DEL_EOS}, {"KEY_INS_LINE", KEY_INS_LINE},
	{"KEY_DEL_LINE", KEY_DEL_LINE}, {"KEY_FN", KEY_FN}, {"KEY_FN_ESC", KEY_FN_ESC}, {"KEY_FN_F1", KEY_FN_F1},
	{"KEY_FN_F2", KEY_FN_F2}, {"KEY_FN_F3", KEY_FN_F3}, {"KEY_FN_F4", KEY_FN_F4}, {"KEY_FN_F5", KEY_FN_F5},
	{"KEY_FN_F6", KEY_FN_F6}, {"KEY_FN_F7", KEY_FN_F7}, {"KEY_FN_F8", KEY_FN_F8}, {"KEY_FN_F9", KEY_FN_F9},
	{"KEY_FN_F10", KEY_FN_F10}, {"KEY_FN_F11", KEY_FN_F11}, {"KEY_FN_F12", KEY_FN_F12}, {"KEY_FN_1", KEY_FN_1},
	{"KEY_FN_2", KEY_FN_2}, {"KEY_FN_D", KEY_FN_D}, {"KEY_FN_E", KEY_FN_E}, {"KEY_FN_F", KEY_FN_F},
	{"KEY_FN_S", KEY_FN_S}, {"KEY_FN_B", KEY_FN_B}, {"KEY_BRL_DOT1", KEY_BRL_DOT1}, {"KEY_BRL_DOT2", KEY_BRL_DOT2},
	{"KEY_BRL_DOT3", KEY_BRL_DOT3}, {"KEY_BRL_DOT4", KEY_BRL_DOT4}, {"KEY_BRL_DOT5", KEY_BRL_DOT5},
	{"KEY_BRL_DOT6", KEY_BRL_DOT6}, {"KEY_BRL_DOT7", KEY_BRL_DOT7}, {"KEY_BRL_DOT8", KEY_BRL_DOT8},
	{"KEY_BRL_DOT9", KEY_BRL_DOT9}, {"KEY_BRL_DOT10", KEY_BRL_DOT10}, {"KEY_NUMERIC_0", KEY_NUMERIC_0},
	{"KEY_NUMERIC_1", KEY_NUMERIC_1}, {"KEY_NUMERIC_2", KEY_NUMERIC_2}, {"KEY_NUMERIC_3", KEY_NUMERIC_3},
	{"KEY_NUMERIC_4", KEY_NUMERIC_4}, {"KEY_NUMERIC_5", KEY_NUMERIC_5}, {"KEY_NUMERIC_6", KEY_NUMERIC_6},
	{"KEY_NUMERIC_7", KEY_NUMERIC_7}, {"KEY_NUMERIC_8", KEY_NUMERIC_8}, {"KEY_NUMERIC_9", KEY_NUMERIC_9},
	{"KEY_NUMERIC_STAR", KEY_NUMERIC_STAR}, {"KEY_NUMERIC_POUND", KEY_NUMERIC_POUND},
	{"KEY_NUMERIC_A", KEY_NUMERIC_A}, {"KEY_NUMERIC_B", KEY_NUMERIC_B}, {"KEY_NUMERIC_C", KEY_NUMERIC_C},
	{"KEY_NUMERIC_D", KEY_NUMERIC_D}, {"KEY_CAMERA_FOCUS", KEY_CAMERA_FOCUS}, {"KEY_WPS_BUTTON", KEY_WPS_BUTTON},
	{"KEY_TOUCHPAD_TOGGLE", KEY_TOUCHPAD_TOGGLE}, {"KEY_TOUCHPAD_ON", KEY_TOUCHPAD_ON},
	{"KEY_TOUCHPAD_OFF", KEY_TOUCHPAD_OFF}, {"KEY_CAMERA_ZOOMIN", KEY_CAMERA_ZOOMIN},
	{"KEY_CAMERA_ZOOMOUT", KEY_CAMERA_ZOOMOUT}, {"KEY_CAMERA_UP", KEY_CAMERA_UP},
	{"KEY_CAMERA_DOWN", KEY_CAMERA_DOWN}, {"KEY_CAMERA_LEFT", KEY_CAMERA_LEFT},
	{"KEY_CAMERA_RIGHT", KEY_CAMERA_RIGHT}, {"KEY_ATTENDANT_ON", KEY_ATTENDANT_ON},
	{"KEY_ATTENDANT_OFF", KEY_ATTENDANT_OFF}, {"KEY_ATTENDANT_TOGGLE", KEY_ATTENDANT_TOGGLE},
	{"KEY_LIGHTS_TOGGLE", KEY_LIGHTS_TOGGLE}, {"KEY_ALS_TOGGLE", KEY_ALS_TOGGLE},

	{"KEY_TASKMANAGER", KEY_TASKMANAGER}, {"KEY_JOURNAL", KEY_JOURNAL}, {"KEY_CONTROLPANEL", KEY_CONTROLPANEL},
	{"KEY_APPSELECT", KEY_APPSELECT}, {"KEY_SCREENSAVER", KEY_SCREENSAVER}, {"KEY_VOICECOMMAND", KEY_VOICECOMMAND},
	{"KEY_BRIGHTNESS_MIN", KEY_BRIGHTNESS_MIN},
	{"KEY_BRIGHTNESS_MAX", KEY_BRIGHTNESS_MAX}, {"KEY_KBDINPUTASSIST_PREV", KEY_KBDINPUTASSIST_PREV},
	{"KEY_KBDINPUTASSIST_NEXT", KEY_KBDINPUTASSIST_NEXT},
	{"KEY_KBDINPUTASSIST_PREVGROUP", KEY_KBDINPUTASSIST_PREVGROUP},
	{"KEY_KBDINPUTASSIST_NEXTGROUP", KEY_KBDINPUTASSIST_NEXTGROUP},
	{"KEY_KBDINPUTASSIST_ACCEPT", KEY_KBDINPUTASSIST_ACCEPT},
	{"KEY_KBDINPUTASSIST_CANCEL", KEY_KBDINPUTASSIST_CANCEL}, {"KEY_RIGHT_UP", KEY_RIGHT_UP},
	{"KEY_RIGHT_DOWN", KEY_RIGHT_DOWN}, {"KEY_LEFT_UP", KEY_LEFT_UP}, {"KEY_LEFT_DOWN", KEY_LEFT_DOWN},
	{"KEY_ROOT_MENU", KEY_ROOT_MENU}, {"KEY_MEDIA_TOP_MENU", KEY_MEDIA_TOP_MENU},
	{"KEY_NUMERIC_11", KEY_NUMERIC_11}, {"KEY_NUMERIC_12", KEY_NUMERIC_12}, {"KEY_AUDIO_DESC", KEY_AUDIO_DESC},
	{"KEY_3D_MODE", KEY_3D_MODE}, {"KEY_NEXT_FAVORITE", KEY_NEXT_FAVORITE}, {"KEY_STOP_RECORD", KEY_STOP_RECORD},
	{"KEY_PAUSE_RECORD", KEY_PAUSE_RECORD}, {"KEY_VOD", KEY_VOD}, {"KEY_UNMUTE", KEY_UNMUTE},
	{"KEY_FASTREVERSE", KEY_FASTREVERSE}, {"KEY_SLOWREVERSE", KEY_SLOWREVERSE}, {"KEY_DATA", KEY_DATA},

	{"KEY_MIN_INTERESTING", KEY_MIN_INTERESTING},
	{"BTN_MISC", BTN_MISC}, {"BTN_0", BTN_0}, {"BTN_1", BTN_1}, {"BTN_2", BTN_2}, {"BTN_3", BTN_3},
	{"BTN_4", BTN_4}, {"BTN_5", BTN_5}, {"BTN_6", BTN_6}, {"BTN_7", BTN_7}, {"BTN_8", BTN_8}, {"BTN_9", BTN_9},
	{"BTN_MOUSE", BTN_MOUSE}, {"BTN_LEFT", BTN_LEFT}, {"BTN_RIGHT", BTN_RIGHT}, {"BTN_MIDDLE", BTN_MIDDLE},
	{"BTN_SIDE", BTN_SIDE}, {"BTN_EXTRA", BTN_EXTRA}, {"BTN_FORWARD", BTN_FORWARD}, {"BTN_BACK", BTN_BACK},
	{"BTN_TASK", BTN_TASK}, {"BTN_JOYSTICK", BTN_JOYSTICK}, {"BTN_TRIGGER", BTN_TRIGGER}, {"BTN_THUMB", BTN_THUMB},
	{"BTN_THUMB2", BTN_THUMB2}, {"BTN_TOP", BTN_TOP}, {"BTN_TOP2", BTN_TOP2}, {"BTN_PINKIE", BTN_PINKIE},
	{"BTN_BASE", BTN_BASE}, {"BTN_BASE2", BTN_BASE2}, {"BTN_BASE3", BTN_BASE3}, {"BTN_BASE4", BTN_BASE4},
	{"BTN_BASE5", BTN_BASE5}, {"BTN_BASE6", BTN_BASE6}, {"BTN_DEAD", BTN_DEAD}, {"BTN_GAMEPAD", BTN_GAMEPAD},
	{"BTN_SOUTH", BTN_SOUTH}, {"BTN_A", BTN_A}, {"BTN_EAST", BTN_EAST}, {"BTN_B", BTN_B}, {"BTN_C", BTN_C},
	{"BTN_NORTH", BTN_NORTH}, {"BTN_X", BTN_X}, {"BTN_WEST", BTN_WEST}, {"BTN_Y", BTN_Y}, {"BTN_Z", BTN_Z},
	{"BTN_TL", BTN_TL}, {"BTN_TR", BTN_TR}, {"BTN_TL2", BTN_TL2}, {"BTN_TR2", BTN_TR2}, {"BTN_SELECT", BTN_SELECT},
	{"BTN_START", BTN_START}, {"BTN_MODE", BTN_MODE}, {"BTN_THUMBL", BTN_THUMBL}, {"BTN_THUMBR", BTN_THUMBR},
	{"BTN_DIGI", BTN_DIGI}, {"BTN_TOOL_PEN", BTN_TOOL_PEN}, {"BTN_TOOL_RUBBER", BTN_TOOL_RUBBER},
	{"BTN_TOOL_BRUSH", BTN_TOOL_BRUSH}, {"BTN_TOOL_PENCIL", BTN_TOOL_PENCIL},
	{"BTN_TOOL_AIRBRUSH", BTN_TOOL_AIRBRUSH}, {"BTN_TOOL_FINGER", BTN_TOOL_FINGER},
	{"BTN_TOOL_MOUSE", BTN_TOOL_MOUSE}, {"BTN_TOOL_LENS", BTN_TOOL_LENS}, {"BTN_TOOL_QUINTTAP", BTN_TOOL_QUINTTAP},
	{"BTN_TOUCH", BTN_TOUCH}, {"BTN_STYLUS", BTN_STYLUS},
	{"BTN_STYLUS2", BTN_STYLUS2}, {"BTN_TOOL_DOUBLETAP", BTN_TOOL_DOUBLETAP},
	{"BTN_TOOL_TRIPLETAP", BTN_TOOL_TRIPLETAP}, {"BTN_TOOL_QUADTAP", BTN_TOOL_QUADTAP}, {"BTN_WHEEL", BTN_WHEEL},
	{"BTN_GEAR_DOWN", BTN_GEAR_DOWN}, {"BTN_GEAR_UP", BTN_GEAR_UP}, {"BTN_DPAD_UP", BTN_DPAD_UP},
	{"BTN_DPAD_DOWN", BTN_DPAD_DOWN}, {"BTN_DPAD_LEFT", BTN_DPAD_LEFT}, {"BTN_DPAD_RIGHT", BTN_DPAD_RIGHT},
	{"BTN_TRIGGER_HAPPY", BTN_TRIGGER_HAPPY}, {"BTN_TRIGGER_HAPPY1", BTN_TRIGGER_HAPPY1},
	{"BTN_TRIGGER_HAPPY2", BTN_TRIGGER_HAPPY2}, {"BTN_TRIGGER_HAPPY3", BTN_TRIGGER_HAPPY3},
	{"BTN_TRIGGER_HAPPY4", BTN_TRIGGER_HAPPY4}, {"BTN_TRIGGER_HAPPY5", BTN_TRIGGER_HAPPY5},
	{"BTN_TRIGGER_HAPPY6", BTN_TRIGGER_HAPPY6}, {"BTN_TRIGGER_HAPPY7", BTN_TRIGGER_HAPPY7},
	{"BTN_TRIGGER_HAPPY8", BTN_TRIGGER_HAPPY8}, {"BTN_TRIGGER_HAPPY9", BTN_TRIGGER_HAPPY9},
	{"BTN_TRIGGER_HAPPY10", BTN_TRIGGER_HAPPY10}, {"BTN_TRIGGER_HAPPY11", BTN_TRIGGER_HAPPY11},
	{"BTN_TRIGGER_HAPPY12", BTN_TRIGGER_HAPPY12}, {"BTN_TRIGGER_HAPPY13", BTN_TRIGGER_HAPPY13},
	{"BTN_TRIGGER_HAPPY14", BTN_TRIGGER_HAPPY14}, {"BTN_TRIGGER_HAPPY15", BTN_TRIGGER_HAPPY15},
	{"BTN_TRIGGER_HAPPY16", BTN_TRIGGER_HAPPY16}, {"BTN_TRIGGER_HAPPY17", BTN_TRIGGER_HAPPY17},
	{"BTN_TRIGGER_HAPPY18", BTN_TRIGGER_HAPPY18}, {"BTN_TRIGGER_HAPPY19", BTN_TRIGGER_HAPPY19},
	{"BTN_TRIGGER_HAPPY20", BTN_TRIGGER_HAPPY20}, {"BTN_TRIGGER_HAPPY21", BTN_TRIGGER_HAPPY21},
	{"BTN_TRIGGER_HAPPY22", BTN_TRIGGER_HAPPY22}, {"BTN_TRIGGER_HAPPY23", BTN_TRIGGER_HAPPY23},
	{"BTN_TRIGGER_HAPPY24", BTN_TRIGGER_HAPPY24}, {"BTN_TRIGGER_HAPPY25", BTN_TRIGGER_HAPPY25},
	{"BTN_TRIGGER_HAPPY26", BTN_TRIGGER_HAPPY26}, {"BTN_TRIGGER_HAPPY27", BTN_TRIGGER_HAPPY27},
	{"BTN_TRIGGER_HAPPY28", BTN_TRIGGER_HAPPY28}, {"BTN_TRIGGER_HAPPY29", BTN_TRIGGER_HAPPY29},
	{"BTN_TRIGGER_HAPPY30", BTN_TRIGGER_HAPPY30}, {"BTN_TRIGGER_HAPPY31", BTN_TRIGGER_HAPPY31},
	{"BTN_TRIGGER_HAPPY32", BTN_TRIGGER_HAPPY32}, {"BTN_TRIGGER_HAPPY33", BTN_TRIGGER_HAPPY33},
	{"BTN_TRIGGER_HAPPY34", BTN_TRIGGER_HAPPY34}, {"BTN_TRIGGER_HAPPY35", BTN_TRIGGER_HAPPY35},
	{"BTN_TRIGGER_HAPPY36", BTN_TRIGGER_HAPPY36}, {"BTN_TRIGGER_HAPPY37", BTN_TRIGGER_HAPPY37},
	{"BTN_TRIGGER_HAPPY38", BTN_TRIGGER_HAPPY38}, {"BTN_TRIGGER_HAPPY39", BTN_TRIGGER_HAPPY39},
	{"BTN_TRIGGER_HAPPY40", BTN_TRIGGER_HAPPY40},

	{"REL_X", REL_X}, {"REL_Y", REL_Y}, {"REL_Z", REL_Z},
	{"REL_WHEEL", REL_WHEEL}, {"REL_HWHEEL", REL_HWHEEL}, {"ABS_X", ABS_X}, {"ABS_Y", ABS_Y},


	{"ABS_MT_SLOT", ABS_MT_SLOT}, {"ABS_MT_TRACKING_ID", ABS_MT_TRACKING_ID},
	{"ABS_MT_POSITION_X", ABS_MT_POSITION_X}, {"ABS_MT_POSITION_Y", ABS_MT_POSITION_Y},
	{"ABS_PRESSURE", ABS_PRESSURE}, {"ABS_MT_PRESSURE", ABS_MT_PRESSURE}
};