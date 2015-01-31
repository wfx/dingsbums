#!/usr/bin/env python
# encoding: utf-8
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

import os

from efl import elementary
from efl.utils.erigo import ErigoGui

json_file = "nfsb.egui"

class MyGui(ErigoGui):
    def __init__(self, *args, **kargs):
        ErigoGui.__init__(self, *args, **kargs)
        # Here you can put your init stuff, if needed

    def elm_button2_clicked_cb(self, btn):
        print('USER CB INVOKED', btn)

def erigo_clicked(obj):

    # Test from file
    egui = MyGui(json_file, verbose=True)

    if obj is None:
        egui.win_main.callback_delete_request_add(lambda o: elementary.exit())

if __name__ == '__main__':
    elementary.init()

    erigo_clicked(None)

    elementary.run()
    elementary.shutdown()
