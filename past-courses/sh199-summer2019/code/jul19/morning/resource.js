let resourceMap = {};

async function loadImages(urlList) {
    for(let url of urlList) {
        await loadImage(url);
    }
}

async function loadImage(url) {
    return new Promise(function(resolve) {
        let img = new Image();
        img.onload = function() {
            resourceMap[url] = img;
            resolve();
        }
        resourceMap[url] = false;
        img.src = url;
    });
}
