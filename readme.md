# QMK Dubeolsik (두벌식)

An experimental QMK code piece that aims to simulate a [Dubeolsik](https://en.wikipedia.org/wiki/Keyboard_layout#Dubeolsik) layout within the QMK firmware.

For Korean typists who prefer a customized English layout (e.g. Colemak), simply changing the layout in the QMK code is impossible as it also changes the Korean layout. There are a few ways to address this issue, each with its own set of limitations:

- Instead add a custom English input method on their computers.
  - Adding a custom layout is difficult.
  - May have an impact on raw inputs, potentially affecting certain scenarios such as games.
- Add a custom layer and QWERTY layer to the keyboard. Toggle the input method and layer at the same time.
  - The sync between the input method and the layout is not guaranteed. e.g. The input method may depend on each program window

Handling the Korean input method inside the QMK code can solve above limitations.

## Prerequisites

This code piece utilizes the QMK Unicode feature. Some installations or modifications may be necessary since Unicode input methods are not enabled by default in most operating systems.
Please read the [QMK Firmware documentation](https://docs.qmk.fm/#/feature_unicode?id=input-modes) and follow the OS-specific instruction.

Additionally for WinCompose users, the default compose key (Right Alt) will conflict with the Korean IME. Perform one of the following:

- Set the compose key to a different key, and edit `UNICODE_KEY_WINC` value (e.g. `KC_F13`) in `config.h` file
- Remove the Korean IME

## Configuration

In `keymaps.c` file, edit `keymaps` and `dbs_keymap` to your own keyboard layout.
