#pragma once

#include <windows.h>
#include <tlhelp32.h>
#include <d3d9.h>

#include <stdint.h>

#include <vector>

#include "legacy/hook.h"
#include "legacy/signatures.h"
#include "legacy/hitobject.h"
#include "memory.h"
#include "legacy/clrhost.h"

#include "legacy/features/relax.h"
#include "legacy/features/aimbot.h"
#include "legacy/features/difficulty.h"
// #include "legacy/features/discord_rpc.h"
#include "legacy/features/replay.h"
// #include "legacy/features/score_multiplier.h"
// #include "legacy/features/unmod_flashlight.h"
// #include "legacy/features/timewarp.h"
// #include "legacy/features/hidden_remover.h"

#include "imgui.h"

typedef HRESULT (__stdcall *twglSwapBuffers)(IDirect3DDevice9* pDevice);

struct CodeStart
{
    const char *name;
    uintptr_t *ptr;
};

extern uintptr_t beatmap_onload_code_start;
extern uintptr_t beatmap_onload_offset;
extern uintptr_t beatmap_onload_hook_jump_back;

extern uintptr_t current_scene_code_start;
extern uintptr_t current_scene_offset;
extern Scene *current_scene_ptr;

extern uintptr_t selected_song_code_start;
extern uintptr_t selected_song_ptr;

extern uintptr_t audio_time_code_start;
extern uintptr_t audio_time_ptr;

extern uintptr_t osu_manager_code_start;
extern uintptr_t osu_manager_ptr;

extern uintptr_t selected_mods_code_start;
extern Mods *selected_mods_ptr;

extern uintptr_t update_mods_code_start;
extern uintptr_t update_mods_offset;

extern uintptr_t osu_client_id_code_start;
extern char osu_client_id[64];

extern uintptr_t osu_username_code_start;
extern char osu_username[32];

extern uintptr_t dispatch_table_id;
extern uintptr_t nt_user_send_input_dispatch_table_id_found;

extern uintptr_t selected_song_offset;
extern uintptr_t audio_time_offset;
extern uintptr_t osu_manager_offset;
extern uintptr_t binding_manager_offset;
extern uintptr_t client_id_offset;
extern uintptr_t username_offset;
// extern uintptr_t check_timewarp_offset;
// extern uintptr_t hom_update_vars_hidden_loc;
// extern uintptr_t score_multiplier_code_start;
// extern uintptr_t score_multiplier_offset;
// extern uintptr_t score_multiplier_hook_jump_back;
// extern uintptr_t update_flashlight_code_start;
// extern uintptr_t check_flashlight_code_start;
// extern uintptr_t update_timing_code_start;
// extern uintptr_t set_playback_rate_code_start;
// extern uintptr_t set_playback_rate_jump_back;
// extern uintptr_t set_playback_rate_original_mov_addr;

extern twglSwapBuffers wglSwapBuffersGateway;

extern Hook<Trampoline32> SwapBuffersHook;
extern Hook<Trampoline32> SceneHook;
extern Hook<Trampoline32> UpdateModsHook;
extern Hook<Detour32> BeatmapOnLoadHook;

extern float memory_scan_progress;

inline bool all_code_starts_found();

void init_hooks();

void enable_notify_hooks();
void disable_notify_hooks();

void enable_update_mods_hook();
void disable_update_mods_hook();

void enable_nt_user_send_input_patch();
void disable_nt_user_send_input_patch();

void notify_on_beatmap_load();
void notify_on_scene_change();
void notify_on_update_mods();

void destroy_hooks();
void destroy_hooks_except_swap();
