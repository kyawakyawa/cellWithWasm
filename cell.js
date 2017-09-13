const memory = new WebAssembly.Memory({
    initial: 256,
    maximum: 1024
}),
    imports = {
        env: {
            memoryBase: 0,
            tableBase: 0,
            memory: memory,
            table: new WebAssembly.Table({
                initial: 0,
                element: "anyfunc"
            })
        }
    },
    memoryBuffer = new Uint8ClampedArray(memory.buffer);

const loadWasm = async(src) => {
    const bin = await fetch(src);
    const bytes = await bin.arrayBuffer();
    const results = await WebAssembly.instantiate(bytes, imports);
    return results.instance;
};
const canvas = document.getElementById('canvas'),
ctx = canvas.getContext('2d');

const fillCanvas = (carr) => {
  ctx.putImageData(new ImageData(carr, canvas.width, canvas.height), 0, 0);
};


loadWasm('./cell.wasm').then(instance => {
    // この中に色々書いていきます
    instance.exports._resetField(0, canvas.width, canvas.height);

    const loop = () => {
        instance.exports._nextCell(0, canvas.width);
        fillCanvas(memoryBuffer.slice(0, canvas.width * canvas.height * 4));
        window.requestAnimationFrame(() => {
            loop();
        });
    };

    loop();
},() => {
    console.log("aaa");
});

