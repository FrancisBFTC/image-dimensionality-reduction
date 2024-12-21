// Caminho para a biblioteca
function gray_image = to_grayscale(image)
    [rows, cols, channels] = size(image);
    if channels ~= 3 then
        error("A imagem precisa ser colorida (RGB).");
    end
    
    gray_image = zeros(rows, cols); // Inicializa a matriz em tons de cinza
    
    for x = 1:rows
        for y = 1:cols
            r = image(x, y, 1);
            g = image(x, y, 2);
            b = image(x, y, 3);
            // Fórmula para conversão
            gray_image(x, y) = 0.299 * r + 0.587 * g + 0.114 * b;
        end
    end
    
    gray_image = uint8(gray_image); // Converte para uint8
endfunction

function bw_image = to_black_and_white(image, threshold)
    if ~exists("threshold") then
        threshold = 128; // Valor padrão para o limiar
    end
    
    // Converte para tons de cinza primeiro
    gray_image = to_grayscale(image);
    
    [rows, cols] = size(gray_image);
    bw_image = zeros(rows, cols); // Inicializa a matriz em preto e branco
    
    for x = 1:rows
        for y = 1:cols
            // Aplica o limiar
            if gray_image(x, y) >= threshold then
                bw_image(x, y) = 255; // Branco
            else
                bw_image(x, y) = 0;   // Preto
            end
        end
    end
    
    bw_image = uint8(bw_image); // Converte para uint8
endfunction


// Exemplo de uso
image = imread("image.jpg");
gray_image = to_grayscale(image);
bw_image = to_black_and_white(image, 128);

// Mostrar as imagens
imshow(gray_image);
imshow(bw_image);
