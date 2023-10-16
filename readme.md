# QMK Dubeolsik (두벌식)

An experimental QMK code piece that aims to simulate a [Dubeolsik](https://en.wikipedia.org/wiki/Keyboard_layout#Dubeolsik) layout within the QMK firmware.

For Korean typists who prefer a customized English layout (e.g. Colemak), simply remapping the QWERTY layout is not a viable option, as it would also scramble the Korean layout. There are a few ways to address this issue, each with its own set of limitations:

- Instead add a custom English input method on their computers.
  - Adding a custom layout to a computer is difficult.
  - May have an impact on raw inputs, potentially affecting certain scenarios such as games.
- Add an additional layer to the keyboard. Toggle the input method and layer at the same time.
  - The sync between the input method and the layout is not guaranteed. e.g. The input method may depend on each program window

This custom QMK code piece can overcome above limitations by directly inputting Korean letters. For instance, it will send "ㅂ" instead of "KC_Q". It tries to combine letters interactively, just like how Windows Korean IME works.

## Prerequisites

This code piece utilizes the QMK Unicode feature. Some installations or modifications may be necessary since Unicode input methods are not enabled by default in most operating systems.
Please read the [QMK Firmware documentation](https://docs.qmk.fm/#/feature_unicode?id=input-modes) and follow the OS-specific instruction.

Additionally for WinCompose users, the default compose key (Right Alt) will conflict with the Korean IME. Perform one of the following:

- Set the compose key to a different key, and edit `UNICODE_KEY_WINC` value (e.g. `KC_F13`) in `config.h` file
- Remove the Korean IME

## Configuration

In `keymaps.c` file, edit `keymaps[][MATRIX_ROWS][MATRIX_COLS]` and `dbs_keymap[MATRIX_ROWS][MATRIX_COLS]` to your own keyboard layout.

Keyboards do not know when you switch between program windows, so a timer is implemented to reset the korean input.
The timer duration is specified as `DBS_TIMEOUT_MS` in `config.h` file.
