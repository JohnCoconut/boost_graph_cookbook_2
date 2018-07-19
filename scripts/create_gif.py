"""
Create a gif file from a list of graphviz dot files.
Assume the dot file name is prefixed with 'dotfile' and ends with a
number. 'dotfile42' is a valid format.
"""

import os
from subprocess import call

import imageio


def get_image_files(prefix='dotfile'):
    """Get a list of graphviz dot files, sort them by sequence number.
    for example, ['dotfile1', 'dotfile2', 'dotfile3', 'dotfile4'].
    Call 'dot -Tpng dotfile* -O' to generate png file. Return a list of
    png image file names.
    Keyword arguments:
    prefix -- the prefix between numeric sequence
    """
    files = []
    for file in os.listdir():
        filename = os.fsdecode(file)
        if filename.startswith(prefix):
            call(['dot', '-Tpng', filename, '-O'])
            files.append(filename + '.png')
        files.sort(key=lambda f: int(f[7:-4]))
    return files


def create_gif(files):
    """Create gif from a list of png files"""
    with imageio.get_writer('movie.gif', mode='I', duration=1) as writer:
        for file in files:
            image = imageio.imread(file)
            writer.append_data(image)


if __name__ == '__main__':
    image_files = get_image_files()
    create_gif(image_files)
