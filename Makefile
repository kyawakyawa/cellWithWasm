build:
	emcc -Os -s WASM=1 -s SIDE_MODULE=1 -o cell.wasm cell.c
