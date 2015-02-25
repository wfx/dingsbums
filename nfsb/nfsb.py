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
# API: https://lazka.github.io/pgi-docs/#LightDM-1
#

import os
import sys

from efl import elementary
from efl.utils.erigo import ErigoGui

prj_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "nfsb")
json_file = os.path.join(prj_path, "nfsb.egui")

class NFSB(ErigoGui):
    def __init__(self, *args, **kargs):
        ErigoGui.__init__(self, *args, **kargs)
        self.elm_win1.callback_delete_request_add(lambda o: elementary.exit())


if __name__ == '__main__':
    elementary.init()
    nfsb = NFSB()
    elementary.run()
    elementary.shutdown()
