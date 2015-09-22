//Класс, отвечающий за маппинг именомание картинки - путь.
//Как-то так:
//class ImageStorage
//
//    IMAGE_PATH_BASE = {
//        background: 'resources/images/bg.png',
//        head:       'resources/images/head.png',
//        person:     'resources/images/person.png',
//        apple:      'resources/images/apple.png'
//    }
//
//    attr_reader :image_base
//
//    def initialize
//        @image_base = {}
//    end
//
//    def get_by_name(image_name)
//        @image_base[image_name.to_sym] ||= Texture.new(Gdx.files.internal(RELATIVE_ROOT + IMAGE_PATH_BASE[image_name]))
//        @image_base[image_name.to_sym]
//    end
//end