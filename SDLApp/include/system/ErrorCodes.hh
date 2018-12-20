#pragma once

enum ErrorCode {
    OK = 0,
    INIT_FAILED,
    CREATE_WINDOW_FAILED,
    INVALID_IMG_FLAGS,
    CREATE_RENDERER_FAILED,
    TEXTURE_LOAD_FAILED
};