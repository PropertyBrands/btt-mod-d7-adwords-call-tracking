(function($) {
    Drupal.adwords_change_numbers = function(formatted_number, unformatted_number ){
        if(typeof Drupal.settings.adwords_call_tracking != 'undefined') {
            var $selectors = $(Drupal.settings.adwords_call_tracking.css_selectors);
            $selectors.each(function(el, index) {
                $(this).text(formatted_number);
            });
        }
    };

    Drupal.behaviors.adwords_call_tracking = {
        attach: function(context, settings) {
            if(typeof _googWcmGet == 'function' && typeof Drupal.settings.adwords_call_tracking != 'undefined') {
                var num = Drupal.settings.adwords_call_tracking.phone_number;
                _googWcmGet(Drupal.adwords_change_numbers, num);
            }
        }
    };
})(jQuery);