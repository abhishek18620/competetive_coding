#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 weirdo <weirdo@Hack-Box>
#
# Distributed under terms of the MIT license.

"""

"""
from random import *

ind = 1
with open("random_input.txt", "w") as f1:
    for i in range(0, 100000):
        f1.write(str(randint(1, 100000)) + '\n')
