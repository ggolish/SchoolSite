resourceMap = {};

async function loadImages(urlList) {
  for(let url of urlList) {
    let rv = await loadImage(url);
    if(!rv) {
      console.error("Unable to load image '" + url + "'.");
    }
  }
}

async function loadImage(url) {
  return new Promise(resolve => {
    let img = new Image();
    img.onload = () => {
      resourceMap[url] = img;
      resolve(true);
    }
    img.onerror = () => {
      resolve(false);
    }
    resourceMap[url] = false;
    img.src = url;
  });
}

function getImage(url) {
  if(resourceMap.hasOwnProperty(url) == false) {
    console.error("Image '" + url + "' does not exist");
    return null;
  } else if(resourceMap[url] == false) {
    console.error("Image '" + url + "' is not loaded.");
    return null;
  }
  return resourceMap[url];
}
