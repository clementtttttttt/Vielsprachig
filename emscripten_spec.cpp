#include <string>
#include "emscripten_spec.h"
#include <imgui.h>

#ifdef __EMSCRIPTEN__



extern "C" {
EMSCRIPTEN_KEEPALIVE
void spoof_event(int in, bool isctrl) {

	uint16_t ev = in;

	ImGuiIO &io = ImGui::GetIO();

	if (isctrl) {
		io.AddInputCharacter(ImGuiKey_LeftCtrl);
	}

	io.AddInputCharacterUTF16(ev);
	io.ClearInputKeys();
	io.ClearInputCharacters();

	//    io.AddKeyEvent(ImGui::GetKey, )
}
}

EM_JS(void, t_vk_js, (bool enable), {
	var inp = document.getElementById('minput');
	var c = document.getElementById('canvas');

	if (enable) {
		if (document.activeElement != inp) {
			inp.focus();
			inp.click();
		}
		window.openVirtualKeyboard = true;
	} else {
		document.activeElement.blur();
		window.openVirtualKeyboard = false;
	}
});

void toggle_vkeyboard(bool p_open) { t_vk_js(p_open); }
#endif
